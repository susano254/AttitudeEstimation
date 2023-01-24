import gdb 

class Matrix33Printer:
	def __init__(self, val):
		self.val = val

	def to_string(self):
		m11 = self.val['m11']
		m12 = self.val['m12']
		m13 = self.val['m13']
		m21 = self.val['m21']
		m22 = self.val['m22']
		m23 = self.val['m23']
		m31 = self.val['m31']
		m32 = self.val['m32']
		m33 = self.val['m33']
		return '[{} {} {}] [{} {} {}] [{} {} {}]'.format(m11, m12, m13, m21, m22, m23, m31, m32, m33)

class Vector3Printer:
	def __init__(self, val):
		self.val = val

	def to_string(self):
		x = self.val['x']
		y = self.val['y']
		z = self.val['z']
		return '[{}, {}, {}]'.format(x, y, z)

def my_pretty_printers(val):
	if str(gdb.types.get_basic_type(val.type)) == ('AML::Matrix33'): 
		return Matrix33Printer(val)
	if str(gdb.types.get_basic_type(val.type)) == ('AML::Vector3'): 
		return Vector3Printer(val)
	#print(val.type)
	return None

gdb.pretty_printers.append(my_pretty_printers)