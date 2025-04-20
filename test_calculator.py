import unittest

from calculator import Calculator

class TestCalculator(unittest.TestCase):
    def setUp(self):
        self.calculator = Calculator()

    def test_ten_to_double_zero_input(self): # UnitTest checking for zero when converting from 10 to 2 number system
        self.assertEqual(self.calculator.ten_to_double(0), [0]) # 0 -> 0
    
    def test_ten_to_double_one_input(self): # UnitTest checking for one when converting from 10 to 2 number system
        self.assertEqual(self.calculator.ten_to_double(1), [1]) # 1 -> 1

    def test_ten_to_double(self):  # UnitTest checking any value when converting from 10 to 2 number system
        self.assertEqual(self.calculator.ten_to_double(155), [1,0,0,1,1,0,1,1]) # 155 -> 10011011
    
    def test_ten_to_oct_zero_input(self): # UnitTest checking for zero when converting from 10 to 8 number system
        self.assertEqual(self.calculator.ten_to_oct(0), [0])    # 0 -> 0

    def test_ten_to_oct_one_input(self): # UnitTest checking for one when converting from 10 to 8 number system
        self.assertEqual(self.calculator.ten_to_oct(1), [1])    # 1 -> 1

    def test_ten_to_oct(self): # UnitTest checking any value when converting from 10 to 8 number system
        self.assertEqual(self.calculator.ten_to_oct(77), [1,1,5]) # 77 -> 115

    def test_ten_to_hex_zero_input(self): # UnitTest checking for zero when converting from 10 to 16 number system
        self.assertEqual(self.calculator.ten_to_hex(0), [0])    # 0 -> 0

    def test_ten_to_hex_one_input(self): # UnitTest checking for one when converting from 10 to 16 number system
        self.assertEqual(self.calculator.ten_to_hex(1), ['1'])  # 1 -> 1

    def test_ten_to_hex(self): # UnitTest checking any value when converting from 10 to 16 number system
        self.assertEqual(self.calculator.ten_to_hex(303), ['1', '2', 'F'])  # 303 -> 12F
    
    def test_double_to_ten_zero_input(self): # UnitTest checking for zero when converting from 2 to 10 number system
        self.assertEqual(self.calculator.double_to_ten([0]), (0))   # 0 -> 0   
    
    def test_double_to_ten_one_input(self): # UnitTest checking for one when converting from 2 to 10 number system
         self.assertEqual(self.calculator.double_to_ten([1]), (1))  # 1 -> 1

    def test_double_to_ten(self): # UnitTest checking any value when converting from 2 to 10 number system
        self.assertEqual(self.calculator.double_to_ten([1,0,0,1,1,0,1]), (77)) # 1001101 -> 77
    
    def test_oct_to_ten_zero_input(self): # UnitTest checking for zero when converting from 8 to 10 number system
        self.assertEqual(self.calculator.oct_to_ten([0]), (0))  # 0 -> 0

    def test_oct_to_ten_one_input(self): # UnitTest checking for one when converting from 8 to 10 number system  
        self.assertEqual(self.calculator.oct_to_ten([1]), (1))  # 1 -> 1
    
    def test_oct_to_ten(self): # UnitTest checking any value when converting from 8 to 10 number system
        self.assertEqual(self.calculator.oct_to_ten([1,4,0,6]), (774))  # 1406 -> 774
    
    def test_hex_to_ten_zero_input(self): # UnitTest checking for zero when converting from 16 to 10 number system
        self.assertEqual(self.calculator.hex_to_ten([0]), (0))  # 0 -> 0    
    
    def test_hex_to_ten_one_input(self): # UnitTest checking for one when converting from 16 to 10 number system  
        self.assertEqual(self.calculator.hex_to_ten([1]), (1))  # 1 -> 1
    
    def test_hex_to_ten(self): # UnitTest checking any value when converting from 16 to 10 number system
        self.assertEqual(self.calculator.hex_to_ten(['E', '4']), (228)) # E4 -> 228   

if __name__ == '__main__':
    unittest.main()