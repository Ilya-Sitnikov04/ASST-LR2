
import os

class Calculator:
    def ten_to_double(self, input_value): # Перевод из 10 системы в 2 
        if input_value == 0:
            return [0]
  
        bin_number = []
        while input_value > 0:
            bin_number.append(input_value % 2)
            input_value //= 2
        return bin_number[::-1]
    
    def ten_to_oct(self, input_value): # Перевод из 10 системы в 8 
        if input_value == 0:
            return[0]
        
        bin_number = []
        while input_value > 0:
            bin_number.append(input_value % 8)
            input_value //= 8
        return bin_number[::-1]

    def ten_to_hex(self, input_value): # Перевод из 10 системы в 16 
        if input_value == 0:
            return [0]
            
        hex_number = []
        hex_chars = "0123456789ABCDEF"
        while input_value > 0:
            remainder = input_value % 16
            hex_number.append(hex_chars[remainder])
            input_value //= 16
        return hex_number[::-1]
    
    def double_to_ten(self, input_value): # Перевод из 2 системы в 10
        if not input_value:  
            return 0
        
        decimal_number = 0
        power = 0 
        for digit in reversed(input_value):
            decimal_number += digit * (2 ** power)
            power += 1
        return decimal_number
    
    def oct_to_ten(self, input_value): # Перевод из 8 системы в 10
        if not input_value:  
            return 0
        
        decimal_number = 0
        power = 0 
        for digit in reversed(input_value):
            decimal_number += digit * (8 ** power)
            power += 1
        return decimal_number
    
    def hex_to_ten(self, input_value): # Перевод из 16 системы в 10
            if not input_value:
                return 0
            
            decimal_number = 0
            power = 0
            hex_chars = "0123456789ABCDEF"
            
            for digit in reversed(input_value):
                if isinstance(digit, str): 
                    digit = digit.upper()
                elif isinstance(digit, int): 
                    digit = str(digit)
                
                if digit in hex_chars: 
                    value = hex_chars.index(digit)  
        
                decimal_number += value * (16 ** power)
                power += 1
            
            return decimal_number

def validate_binary_number(input_value):
    for digit in str(input_value):
        if digit not in '01':
            return False
    return True

def validate_octal_number(input_value):
    for digit in str(input_value):
        if digit not in '01234567':
            return False
    return True

def validate_hexadecimal(input_value):
    valid_chars = "0123456789ABCDEF"
    for digit in input_value:
        if digit.upper() not in valid_chars:
            return False
    return True

flag = True
while flag == True:
    try:
        print('1) Перевод из 10 в 2 с.с')
        print('2) Перевод из 10 в 8 с.с')
        print('3) Перевод из 10 в 16 с.с')
        print('4) Перевод из 2 в 10 с.с')
        print('5) Перевод из 8 в 10 с.с')
        print('6) Перевод из 16 в 10 с.с')
        print('0) Выход')
        choice = int(input("Введите номер: "))
        calc = Calculator()
        _ = os.system('cls')
        
        if (choice == 1):
            input_value = int(input("Введите число в 10 с.с. : "))
            print("Число в 2 с.с. : ", ''.join(map(str, calc.ten_to_double(input_value))))
        elif (choice == 2):
            input_value = int(input("Введите число в 10 с.с. : "))
            print("Число в 8 с.с. : ", ''.join(map(str, calc.ten_to_oct(input_value))))
        elif (choice == 3):
            input_value = int(input("Введите число в 10 с.с. : "))
            print("Число в 16 с.с. : ", ''.join(calc.ten_to_hex(input_value)))
        elif (choice == 4):
            input_value = int(input("Введите число в 2 с.с. (например, '101'): "))
            if not validate_binary_number(input_value):
                print("Ошибка! Введите корректное двоичное число (только 0 и 1).")
                continue
            input_value = [int(digit) for digit in str(input_value)]
            print("Число в 10 с.с. : ", calc.double_to_ten(input_value))
        elif (choice == 5):
            input_value = int(input("Введите число в 8 с.с. (например, '131'): "))
            if not validate_octal_number(input_value):
                print("Ошибка! Введите корректное восьмеричное число (только цифры 0-7).")
                continue
            input_value = [int(digit) for digit in str(input_value)]
            print("Число в 10 с.с. : ", calc.oct_to_ten(input_value))
        elif (choice == 6):
            input_value = input("Введите число в 16 с.с. (например, '1F'): ").upper()
            if not validate_hexadecimal(input_value):
                print("Ошибка! Введите корректное шестнадцатеричное число (только цифры 0-9 и буквы A-F).")
                continue
            print("Число в 10 с.с. : ", calc.hex_to_ten(input_value))
        elif (choice == 0):
            flag = False
    except ValueError:
        print("Ошибка! Введите корректное значение.")