import MyString
from cppyy.gbl import MyString

a = MyString(20, '1')
a.clear()
a.append("12345")
print(a.data(), a.size(), a.capacity(), sep=' ')
