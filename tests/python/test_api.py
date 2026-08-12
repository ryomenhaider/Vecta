import pytest

import vecta as vt


def test_construct_from_list():
    A = vt.array([[1, 2], [3, 4]])
    assert A.shape == (2, 2)
    assert A[0, 0] == 1
    assert A[1, 1] == 4


def test_matrix_dims_constructor():
    A = vt.Matrix(2, 3)
    assert A.shape == (2, 3)
    assert A[1, 2] == 0.0
    B = vt.Matrix(2, 2, 5.0)
    assert B[0, 0] == 5.0


def test_matrix_from_list_alias():
    A = vt.Matrix([[1, 2], [3, 4]])
    assert A.shape == (2, 2)


def test_ragged_list_raises():
    with pytest.raises(ValueError):
        vt.array([[1, 2], [3]])


def test_zeros_ones_eye():
    assert vt.zeros((2, 3)).shape == (2, 3)
    assert vt.zeros((2, 2))[0, 0] == 0.0
    assert vt.ones((1, 2))[0, 1] == 1.0
    I = vt.eye(3)
    assert I.shape == (3, 3)
    assert I[0, 0] == 1.0
    assert I[0, 1] == 0.0
    assert vt.identity(2)[1, 1] == 1.0


def test_setitem_and_negative_indices():
    A = vt.zeros((3, 3))
    A[1, 2] = 7.0
    assert A[1, 2] == 7.0
    A[-1, -1] = 9.0
    assert A[2, 2] == 9.0


def test_index_errors():
    A = vt.array([[1, 2], [3, 4]])
    with pytest.raises(IndexError):
        A[2, 0]
    with pytest.raises(IndexError):
        A[0, 5]


def test_transpose_and_T():
    A = vt.array([[1, 2, 3], [4, 5, 6]])
    T = vt.transpose(A)
    assert T.shape == (3, 2)
    assert T[0, 1] == 4
    assert A.T[2, 0] == 3


def test_matmul():
    A = vt.array([[1, 2], [3, 4]])
    B = vt.array([[5, 6], [7, 8]])
    C = vt.matmul(A, B)
    assert C.shape == (2, 2)
    assert C[0, 0] == 19
    assert C[0, 1] == 22
    assert C[1, 0] == 43
    assert C[1, 1] == 50


def test_matmul_dim_mismatch():
    A = vt.array([[1, 2], [3, 4]])
    B = vt.array([[1, 2], [3, 4], [5, 6]])
    with pytest.raises(ValueError):
        vt.matmul(A, B)


def test_add_and_scalar_mul():
    A = vt.array([[1, 2], [3, 4]])
    S = vt.add(A, A)
    assert S[1, 1] == 8
    M = vt.scalar_mul(A, 2.0)
    assert M[0, 0] == 2.0
    assert M[1, 1] == 8.0


def test_is_symmetric():
    S = vt.array([[1, 2], [2, 1]])
    assert vt.is_symmetric(S)
    A = vt.array([[1, 2], [3, 4]])
    assert not vt.is_symmetric(A)


def test_repr():
    A = vt.array([[1, 2], [3, 4]])
    assert repr(A) == "[[1.0, 2.0], [3.0, 4.0]]"
    assert str(A) == repr(A)


def test_version():
    assert vt.__version__ == "0.0.3"
