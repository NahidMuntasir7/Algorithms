for negative numbers:
a mod m = ((a % m) + m) % m

Addition/Subtraction: For subtraction of numbers under modulo:
(a - b) mod m = ((a mod m) - (b mod m) + m) mod m
(a + b) mod m = ((a mod m) + (b mod m)) mod m

Multiplication:
(a * b) mod m = ((a mod m) * (b mod m)) mod m

Division:
a / b mod m = (a * b^(-1)) mod m



