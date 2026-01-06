**University of Engineering and Technology, Lahore**

Department of Computer Science

**User Manual**

**(Modular Arithmetic Calculator)**


  **Team Members**

**Name** Hamda Sami

**Roll Number**2025-CS-42

**Email**[hamda.sami@gmail.com](mailto:hamda.sami@gmail.com)

**Name** Hareema Saleem

**Roll Number** 2025-CS-39

**Email** hareemasaleem4@gmail.com

**Session:** Fall’25 Morning
**Section:** A	       
**Semester:** 1st

**Course:** CSC101 – Discrete Mathematics		
**Teacher:** Mr. Waqas Ali

January 06, 2025

# **USER MANUAL (README file)**

## **Modular Arithmetic Calculator (C++ Console Application)**

## **1. Introduction**

The Modular Arithmetic Calculator is a menu-driven C++ console application designed to perform various number-theoretic and modular arithmetic operations efficiently.

It is intended for students, educators, and researchers studying Discrete Mathematics, Cryptography, and Number Theory.

The application allows users to compute results for:

Modular exponentiation

GCD and Extended Euclidean Algorithm

Modular inverses

Linear congruences

Chinese Remainder Theorem

Mersenne primes

Sieve of Eratosthenes

View calculation history

The program also tracks execution time for most operations and maintains a calculation history during runtime.

## **2. System Requirements**

### **Hardware Requirements**

Any standard computer capable of running Windows OS

### **Software Requirements**

Windows Operating System

C++ Compiler (e.g., GCC, MSVC)

Console that supports:

<windows.h>

<conio.h>

 **Note:** This application is Windows-specific due to the use of windows.h and conio.h.

## **3. Starting the Application**

Compile the source code using a C++ compiler.

Run the executable file.

The main menu will appear on the console screen.

## **4. Main Menu Overview**

The main menu displays numbered options:

[1] Modular Exponentiation
[2] Greatest Common Divisor (GCD)
[3] Extended Euclidean Algorithm (EEA)
[4] Modular Inverse
[5] Linear Congruences
[6] Chinese Remainder Theorem
[7] Mersenne Primes
[8] Sieve of Eratosthenes
[H] History
[9] Exit

Enter the corresponding key to select an operation.

## **5. Functional Modules**

### **5.1 Modular Exponentiation**

**Purpose:**

Computes

[

a^b \mod m

]

**Steps:**

Enter base a

Enter exponent b

Enter modulus m

**Output:**

Computed result

Start and end execution time

**Algorithm Used:**

Fast Modular Exponentiation (Binary Exponentiation)

### **5.2 Greatest Common Divisor (GCD)**

**Purpose:**

Computes the GCD of two integers using the Euclidean Algorithm.

**Steps:**

Enter two integers

Choose whether to display steps (1 = Yes, 0 = No)

**Output:**

GCD value

Optional step-by-step computation

Execution time

### **5.3 Extended Euclidean Algorithm (EEA)**

**Purpose:**

Computes:

GCD(a, b)

Bézout coefficients x and y such that

[

ax + by = gcd(a,b)

]

**Steps:**

Enter two integers

Choose whether to show steps

**Output:**

GCD

Bézout coefficients

Verification of result

Execution time

### **5.4 Modular Inverse**

**Purpose:**

Finds the modular inverse of a modulo m (if it exists).

**Condition:**

Inverse exists only if gcd(a, m) = 1.

**Steps:**

Enter a

Enter m

**Output:**

Modular inverse

Verification

Error message if inverse does not exist

### **5.5 Linear Congruence Solver**

**Purpose:**

Solves linear congruence of the form:

[

ax \equiv b \ (\text{mod } m)

]

**Steps:**

Enter values of a, b, and m

**Output:**

One solution

All possible solutions

Execution time

### **5.6 Chinese Remainder Theorem (CRT)**

**Purpose:**

Solves a system of simultaneous congruences.

**Condition:**

All moduli must be pairwise coprime.

**Steps:**

Enter number of congruences (2–10)

Enter each pair (aᵢ, mᵢ)

**Output:**

Step-by-step CRT calculation

Final solution

Modulus

Execution time

### **5.7 Mersenne Primes**

**Purpose:**

Checks whether:

[

2^p - 1

]

is a **Mersenne prime**.

**Steps:**

Enter value of p

**Output:**

Mersenne number

Prime or not prime result

Execution time

### **5.8 Sieve of Eratosthenes**

**Purpose:**

Finds all prime numbers up to n.

**Steps:**

Enter value of n

**Output:**

List of prime numbers

Total count of primes

Execution time

## **6. History Feature**

Press H from the main menu.

Displays all calculations performed during the current session.

History is stored temporarily and cleared when the program exits.

## **7. Exit Option**

Press **9** from the main menu.

Confirm exit by entering Y or y.

## **8. Error Handling & Notes**

Invalid inputs are handled with appropriate messages.

Some features require specific mathematical conditions (e.g., coprime numbers).

Modulus must be positive.

Large inputs may affect performance due to computational limits.

## **9. Conclusion**

The **Modular Arithmetic Calculator** provides a comprehensive and interactive way to explore important mathematical algorithms used in cryptography and number theory.

Its structured menu, step-by-step outputs, and timing analysis make it an effective educational and practical tool.