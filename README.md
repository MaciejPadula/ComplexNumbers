# ComplexNumbers
C++ library for complex numbers

# Usage
To use library just simply add files to your project directory and add #include "folder/complex.h" line to your code. <br/>
To create new object of Complex type: <br/>
<ul>
  <li>
  As pointer:
  </li>
  Complex* number = new Complex(RealPart, ImaginaryPart);
  <li>
  As variable:
  </li>
  Complex number(RealPart, ImaginaryPart);
</ul>

# Documentation

Constructor:
<ul>
  <li>Complex(double real, double imaginary)</li>
  <li>Complex(double real)</li>
</ul>
Methods:
<ul>
  <li>static Complex fromExp(double argument, double module)</li>
  This method returns new complex number from given argument and module.
  <li>double real()</li>
  Returns real part of complex number object.
  <li>double imaginary()</li>
  Returns imaginary part of complex number object.
</ul>
