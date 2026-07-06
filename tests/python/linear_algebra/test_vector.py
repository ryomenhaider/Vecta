from vecta import linear_algebra


def test_add():
    a = linear_algebra.Vector([1.0, 2.0, 3.0])
    b = linear_algebra.Vector([4.0, 5.0, 6.0])
    c = a + b
    assert c.to_list() == [5.0, 7.0, 9.0]


def test_dot():
    a = linear_algebra.Vector([1.0, 2.0, 3.0])
    b = linear_algebra.Vector([4.0, 5.0, 6.0])
    assert a.dot(b) == 32.0


def test_norm():
    a = linear_algebra.Vector([3.0, 4.0])
    assert a.norm() == 5.0
