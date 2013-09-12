#include <iostream>
#include <fstream>
#include <ostream>
#include "hdf5.h"
#include "mkl_cblas.h"

class Matrix
{
  public:
    Matrix(const int &, const int &);
    ~Matrix();
    int cols() const {return m_cols;}
    int rows() const {return m_rows;}
    double * ptr() const { return m_data; }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
  
  private:
    int m_rows;
    int m_cols;
    int m_length;
    double * m_data;

};

Matrix::Matrix(const int &rows, const int &cols)
{
    m_rows = rows;
    m_cols = cols;
    m_length = m_rows*m_cols;
    m_data = new double[m_length];
    std::fill( m_data, m_data + m_length, 0 );
}

Matrix::~Matrix()
{
    delete [] m_data;
}

std::ostream& operator<<(std::ostream& os, const Matrix& M)
{
    for(int r=0; r<M.rows(); ++r)
    {
        for(int c=0; c<M.cols(); ++c)
        {
            int index = r*M.cols() + c;
            os << M.ptr()[index] << " "; 
        }
        os << std::endl;

    }
    return os;
}


namespace util
{

Matrix read_hdf(const std::string &filename){

    hid_t file_id, dataset_id, space_id, property_id; 
    herr_t status;

    //Create a new file using the default properties.
    file_id = H5Fopen (filename.c_str(), H5F_ACC_RDONLY, H5P_DEFAULT);
    dataset_id = H5Dopen(file_id, "x", H5P_DEFAULT);
    space_id = H5Dget_space(dataset_id);
    int length = H5Sget_simple_extent_npoints(space_id);
    hsize_t  dims[2];
    hsize_t  mdims[2];
    status = H5Sget_simple_extent_dims(space_id,dims,mdims);
    
    Matrix tmp(dims[0],dims[1]);

    status = H5Dread(dataset_id, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL,
                H5P_DEFAULT, tmp.ptr());

    status = H5Sclose(space_id);
    status = H5Dclose(dataset_id);
    status = H5Fclose(file_id);

    std::cout << tmp.ptr() << std::endl;
    return tmp;

}

void write_hdf(const std::string &filename, const Matrix& tmp){

    hid_t file_id, dataset_id, space_id, property_id; 
    herr_t status;

    hsize_t  dims[2] = {tmp.rows(),tmp.cols()};
   
    
    //Create a new file using the default properties.
    file_id = H5Fcreate (filename.c_str(), H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

    //Create dataspace.  Setting maximum size to NULL sets the maximum
    //size to be the current size.
    space_id = H5Screate_simple (2, dims, NULL);

    //Create the dataset creation property list, set the layout to compact.
    property_id = H5Pcreate (H5P_DATASET_CREATE);
    status = H5Pset_layout (property_id, H5D_CONTIGUOUS);

    // Create the dataset. 
    dataset_id = H5Dcreate (file_id, "x", H5T_NATIVE_DOUBLE, space_id, H5P_DEFAULT, property_id, H5P_DEFAULT);
   
    //Write the data to the dataset.
    status = H5Dwrite (dataset_id, H5T_NATIVE_DOUBLE, H5S_ALL, H5S_ALL, H5P_DEFAULT, tmp.ptr());

    status = H5Sclose(space_id);
    status = H5Dclose(dataset_id);
    status = H5Fclose(file_id);
    status = H5Pclose(property_id);

}

};

void multiply(Matrix &A, Matrix &B, Matrix &C)
{
    double alpha = 1.0;
    double beta = 0.0;
    int M = A.rows();
    int N = B.cols();
    int K = B.cols();
    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                 M, N, K, alpha, A.ptr(), K, B.ptr(), N, beta, C.ptr(), N);
}

int main(int argc, char ** argv)
{

    std::string filename_a = argv[1];
    std::string filename_b = argv[2];
    std::string filename_c = argv[3];

    double * data = 0;
    int m_rows, m_cols = 0;
    
    // Read the file
    Matrix A = util::read_hdf(filename_a);
    std::cout << A.ptr() << std::endl;

    Matrix B = util::read_hdf(filename_b);
    Matrix C(A.rows(),B.cols());

    multiply(A,B,C);

    // std::cout << A << std::endl;
    // std::cout << B << std::endl;
    // std::cout << C << std::endl;

    // Write the file
    util::write_hdf(filename_c, A);


    return 0;
}
