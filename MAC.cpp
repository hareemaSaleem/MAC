#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cmath>
#include <chrono>
#include <string>

using namespace std;
/*============UI FUNCTIONS=======================*/
void pause();
void menu();
void header();
void divider();
void setColor(int color);
/*============FUNCTION PROTOTYPES================*/
long long modExp(long long a, long long b, long long m);
long long GCD(long long x, long long y, bool show = false);
long long EEA(long long a, long long b, long long &x, long long &y, bool show = false);
bool modularInverse(long long a, long long m, long long &inv);
bool Linear(long long a, long long b, long long m, long long &x0, long long &mod, long long &count);
bool CRT(long long a[], long long m[], int k, long long &x, long long &mod);
long long isMersenne(long long p);
void sieve(int n);

/*==============HELPING FUNCTION PROTOTYPE=============*/
string history[20];
int historyCount = 0;
bool isPrime(long long Mp);

/*=============MAIN FUNCTION==========================*/
int main()
{
    menu();
    return 0;
}
/*=============MAIN MENU===========================*/
void menu()
{
    char ch;
    while (true)
    {
        system("cls");
        setColor(5);
        header();
        setColor(7);
        setColor(6);
        cout << "[1].";
        setColor(7);
        cout << "Modular Exponentiation: " << endl;
        setColor(6);
        cout << "[2].";
        setColor(7);

        cout << " Greatest Common Divisor(GCD): " << endl;
        setColor(6);
        cout << "[3].";
        setColor(7);

        cout << " Extended Euclidean Algorithm(EEA): " << endl;
        setColor(6);

        cout << "[4].";
        setColor(7);

        cout << " Modular Inverses: " << endl;
        setColor(6);

        cout << "[5].";
        setColor(7);

        cout << " Linear Congruencies: " << endl;
        setColor(6);

        cout << "[6].";
        setColor(7);

        cout << " Chinese Remainder Theorem: " << endl;
        setColor(6);

        cout << "[7].";
        setColor(7);

        cout << " Mersenne Primes: " << endl;
        setColor(6);

        cout << "[8].";
        setColor(7);

        cout << " Sieve of Erastosthenes: " << endl;
        setColor(6);

        cout << "[H].";
        setColor(7);

        cout << " History: " << endl;
        setColor(6);

        cout << "[9].";
        setColor(7);

        cout << " Exit: " << endl;

        divider();
        cout << "enter the choice: ";
        cin >> ch;

        if (ch == '1')
        {
            system("cls");
            setColor(5);
            header();
            setColor(7);

            divider();
            setColor(3);

            cout << "        MODULAR EXPONENTIATION           ";
            setColor(7);

            divider();
            long long a, b, mod, res;
            cout << "enter the base (a): ";
            cin >> a;
            cout << "Enter the Exponent (b): ";
            cin >> b;
            cout << "Enter the Modulus (m): ";
            cin >> mod;
            if (mod <= 0)
            {
                cout << "Modulus must be positive. \n";
                pause();
            }
            // start time
            auto start_time = chrono::high_resolution_clock::now();
            auto start_system_time = chrono::system_clock::now();

            res = modExp(a, b, mod);

            // end time
            auto end_time = chrono::high_resolution_clock::now();
            auto end_system_time = chrono::system_clock::now();

            // convert system time to human readable time
            time_t start_t = chrono::system_clock::to_time_t(start_system_time);
            time_t end_t = chrono::system_clock::to_time_t(end_system_time);
            setColor(10);
            cout << ">>>Result<<< " << endl;
            setColor(7);
            cout << a << "^" << b << " mod" << mod << " = " << res << endl;

            setColor(6);
            cout << endl
                 << "====TIMING INFORMATION=====" << endl;
            setColor(7);
            cout << "Start time: " << ctime(&start_t);
            cout << "End time: " << ctime(&end_t);

            history[historyCount++] = "ModExp: " + to_string(a) + "^" + to_string(b) + " mod " + to_string(mod) + " = " + to_string(res);
            pause();
        }
        else if (ch == '2')
        {
            system("cls");
            setColor(5);

            header();
            setColor(7);

            divider();
            setColor(3);

            cout << "      GCD (EUCLIDEAN ALGORITHM)        ";
            setColor(7);

            divider();
            long long x, y, res;
            int steps;
            cout << "First integer:";
            cin >> x;
            cout << "Second integer:";
            cin >> y;
            setColor(5);
            cout << "show steps? (1= yes , 0= no): ";
            setColor(7);
            cin >> steps;
            // start time
            auto start_time = chrono::high_resolution_clock::now();
            auto start_system_time = chrono::system_clock::now();

            res = GCD(x, y, steps);

            // end time
            auto end_time = chrono::high_resolution_clock::now();
            auto end_system_time = chrono::system_clock::now();

            // convert system time to human readable time
            time_t start_t = chrono::system_clock::to_time_t(start_system_time);
            time_t end_t = chrono::system_clock::to_time_t(end_system_time);

            setColor(10);
            cout << "GCD (" << x << "," << y << ")= " << res << endl;
            setColor(7);
            setColor(6);
            cout << endl
                 << "====TIMING INFORMATION=====" << endl;
            setColor(7);
            cout << "Start time: " << ctime(&start_t);
            cout << "End time: " << ctime(&end_t);
            history[historyCount++] = "GCD(" + to_string(x) + "," + to_string(y) + ") = " + to_string(res);
            pause();
        }
        else if (ch == '3')
        {
            system("cls");
            setColor(5);

            header();
            setColor(7);

            divider();
            setColor(3);

            cout << "      EXTENDED EUCLIDEAN ALGORITHM        ";
            setColor(7);

            divider();
            long long a, b, x, y;
            int steps;
            cout << "enter first number: ";
            cin >> a;
            cout << "enter the second number: ";
            cin >> b;
            setColor(12);
            cout << "show steps? (1= yes , 0= no): ";
            setColor(7);
            cin >> steps;

            // start time
            auto start_time = chrono::high_resolution_clock::now();
            auto start_system_time = chrono::system_clock::now();

            long long gcd = EEA(a, b, x, y, steps);

            // end time
            auto end_time = chrono::high_resolution_clock::now();
            auto end_system_time = chrono::system_clock::now();

            // convert system time to human readable time
            time_t start_t = chrono::system_clock::to_time_t(start_system_time);
            time_t end_t = chrono::system_clock::to_time_t(end_system_time);

            cout << "GCD: ";
            setColor(10);
            cout << gcd << endl;
            setColor(7);

            cout << "Beziot coefficients are \n x= ";
            setColor(10);

            cout << x;
            setColor(7);

            cout << " y= ";
            setColor(10);

            cout << y << endl;
            setColor(7);
            setColor(12);
            cout << "Verification: ";
            setColor(7);
            cout << a << "(" << x << ") + " << b << "(" << y << ") = " << a * x + b * y << endl;
            setColor(6);
            cout << endl
                 << "====TIMING INFORMATION=====" << endl;
            setColor(7);
            cout << "Start time: " << ctime(&start_t);
            cout << "End time: " << ctime(&end_t);
            history[historyCount++] = "EEA(" + to_string(a) + "," + to_string(b) + ") gcd=" + to_string(gcd);
            pause();
        }
        else if (ch == '4')
        {
            system("cls");
            setColor(5);

            header();
            setColor(7);

            divider();
            setColor(3);

            cout << "     MODULAR INVERSE\n       ";
            setColor(7);

            divider();
            long long a, m;
            cout << "Enter a: ";
            cin >> a;
            cout << "Enter m: ";
            cin >> m;

            long long inv;

            // start time
            auto start_time = chrono::high_resolution_clock::now();
            auto start_system_time = chrono::system_clock::now();

            if (modularInverse(a, m, inv))
            {
                cout << "Modular inverse of " << a << " modulo " << m << " is: " << inv << endl;
                cout << "Verification: (" << a << " * " << inv << ") % " << m << " = " << (a * inv) % m << endl;
            }
            else
            {
                setColor(12);

                cout << "Modular inverse does not exist (gcd != 1)." << endl;
                setColor(7);
            }
            // end time
            auto end_time = chrono::high_resolution_clock::now();
            auto end_system_time = chrono::system_clock::now();

            // convert system time to human readable time
            time_t start_t = chrono::system_clock::to_time_t(start_system_time);
            time_t end_t = chrono::system_clock::to_time_t(end_system_time);

            setColor(6);
            cout << endl
                 << "====TIMING INFORMATION=====" << endl;
            setColor(7);
            cout << "Start time: " << ctime(&start_t);
            cout << "End time: " << ctime(&end_t);
            history[historyCount++] = "ModInv: " + to_string(a) + " ^-1 mod " + to_string(m) + " = " + to_string(inv);
            pause();
        }
        else if (ch == '5')
        {
            system("cls");
            setColor(5);

            header();
            setColor(7);

            divider();
            setColor(3);

            cout << "    LINEAR CONGRUENCE SOLVER\n       ";
            setColor(7);

            divider();
            long long a, b, m;
            cout << "Enter a: ";
            cin >> a;
            cout << "Enter b: ";
            cin >> b;
            cout << "Enter m: ";
            cin >> m;

            long long x0, mod, count;

            // start time
            auto start_time = chrono::high_resolution_clock::now();
            auto start_system_time = chrono::system_clock::now();

            if (!Linear(a, b, m, x0, mod, count))
            {
                setColor(12);

                cout << "No solution exists!" << endl;
                setColor(7);
            }
            // end time
            auto end_time = chrono::high_resolution_clock::now();
            auto end_system_time = chrono::system_clock::now();

            // convert system time to human readable time
            time_t start_t = chrono::system_clock::to_time_t(start_system_time);
            time_t end_t = chrono::system_clock::to_time_t(end_system_time);

            cout << "\nGiven congruence:\n";
            cout << a << "x = " << b << " (mod " << m << ")\n";

            cout << "\nOne solution:\n";
            cout << "x = " << x0 << " (mod " << mod << ")\n";

            cout << "\nAll solutions:\n";
            for (int k = 0; k < count; k++)
            {
                cout << "x = " << x0 + k * mod << endl;
            }
            setColor(6);
            cout << endl
                 << "====TIMING INFORMATION=====" << endl;
            setColor(7);
            cout << "Start time: " << ctime(&start_t);
            cout << "End time: " << ctime(&end_t);
            history[historyCount++] = "Linear: " + to_string(a) + "x = " + to_string(b) + " mod " + to_string(m) + " to x0=" + to_string(x0) + " mod " + std::to_string(mod);
            pause();
        }
        else if (ch == '6')
        {
            system("cls");
            setColor(5);

            header();
            setColor(7);

            divider();
            setColor(3);

            cout << "      CHINESE REMAINDER THEOREM\n       ";
            setColor(7);

            divider();
            int k;
            cout << "Enter number of congruences(max 10): ";
            cin >> k;
            if (k < 2 || k > 10)
            {
                setColor(12);
                cout << endl
                     << "Number of congruences must be between 2 and 10";
                setColor(7);
                pause();
            }

            long long a[10], m[10];
            for (int i = 0; i < k; i++)
            {
                cout << "Enter a[" << i + 1 << "] and m[" << i + 1 << "]: ";
                cin >> a[i] >> m[i];
            }

            cout << "\nGiven congruences are:\n";
            for (int i = 0; i < k; i++)
                cout << "x = " << a[i] << " (mod " << m[i] << ")\n";

            long long x, M;

            // start time
            auto start_time = chrono::high_resolution_clock::now();
            auto start_system_time = chrono::system_clock::now();

            if (!CRT(a, m, k, x, M))
            {
                setColor(12);

                cout << "\nCRT cannot be applied (moduli not coprime)\n";
                setColor(7);

                pause();
                continue;
            }
            // end time
            auto end_time = chrono::high_resolution_clock::now();
            auto end_system_time = chrono::system_clock::now();

            // convert system time to human readable time
            time_t start_t = chrono::system_clock::to_time_t(start_system_time);
            time_t end_t = chrono::system_clock::to_time_t(end_system_time);

            cout << "\nSolution:\n";
            cout << "x = " << x << " (mod " << M << ")\n";

            history[historyCount++] = "CRT: x = " + to_string(x) + " mod " + to_string(M);
            setColor(6);
            cout << endl
                 << "====TIMING INFORMATION=====" << endl;
            setColor(7);
            cout << "Start time: " << ctime(&start_t);
            cout << "End time: " << ctime(&end_t);
            pause();
        }
        else if (ch == '7')
        {
            system("cls");
            setColor(5);

            header();
            setColor(7);

            divider();
            setColor(3);

            cout << "     MERSENNE PRIMES\n     ";
            setColor(7);

            divider();

            long long p;
            cout << "enter the value for p:";
            cin >> p;
            long long Mp = isMersenne(p);

            // start time
            auto start_time = chrono::high_resolution_clock::now();
            auto start_system_time = chrono::system_clock::now();

            if (isPrime(Mp))
            {
                // end time
                auto end_time = chrono::high_resolution_clock::now();
                auto end_system_time = chrono::system_clock::now();

                // convert system time to human readable time
                time_t start_t = chrono::system_clock::to_time_t(start_system_time);
                time_t end_t = chrono::system_clock::to_time_t(end_system_time);

                cout << Mp << " is a Mersenne Prime." << endl;
                history[historyCount++] = "Mersenne: 2^" + to_string(p) + "-1 = " + to_string(Mp) + " is PRIME";
                setColor(6);
                cout << endl
                     << "====TIMING INFORMATION=====" << endl;
                setColor(7);
                cout << "Start time: " << ctime(&start_t);
                cout << "End time: " << ctime(&end_t);
                pause();
            }
            else
            {
                // end time
                auto end_time = chrono::high_resolution_clock::now();
                auto end_system_time = chrono::system_clock::now();

                // convert system time to human readable time
                time_t start_t = chrono::system_clock::to_time_t(start_system_time);
                time_t end_t = chrono::system_clock::to_time_t(end_system_time);

                cout << Mp << " is NOT a Mersenne Prime." << endl;
                history[historyCount++] = "Mersenne: 2^" + to_string(p) + "-1 = " + to_string(Mp) + " is";
                setColor(12);

                cout << " NOT prime";
                setColor(7);
                setColor(6);
                cout << endl
                     << "====TIMING INFORMATION=====" << endl;
                setColor(7);
                cout << "Start time: " << ctime(&start_t);
                cout << "End time: " << ctime(&end_t);
                pause();
            }
        }
        else if (ch == '8')
        {
            system("cls");
            setColor(5);

            header();
            setColor(7);

            divider();
            setColor(3);

            cout << "    SIEVE OF ERATOSTHENES\n      ";
            setColor(7);

            divider();
            int n;
            cout << "enter a number: ";
            cin >> n;

            // start time
            auto start_time = chrono::high_resolution_clock::now();
            auto start_system_time = chrono::system_clock::now();
            sieve(n);
            // end time
            auto end_time = chrono::high_resolution_clock::now();
            auto end_system_time = chrono::system_clock::now();

            // convert system time to human readable time
            time_t start_t = chrono::system_clock::to_time_t(start_system_time);
            time_t end_t = chrono::system_clock::to_time_t(end_system_time);

            setColor(6);
            cout << endl
                 << "====TIMING INFORMATION=====" << endl;
            setColor(7);
            cout << "Start time: " << ctime(&start_t);
            cout << "End time: " << ctime(&end_t);

            pause();
        }
        else if (ch == 'h' || ch == 'H')
        {
            system("cls");
            setColor(5);
            header();
            setColor(7);
            divider();
            setColor(3);
            cout << "  CALCULATION HISTORY\n    ";
            divider();
            if (historyCount == 0)
            {
                cout << "\n NO HISTORY YET!";
            }
            for (int i = 0; i < historyCount; i++)
            {
                setColor(6);

                cout << "[" << i + 1 << "]";
                setColor(7);

                cout << history[i] << endl;
            }
            pause();
        }
        else if (ch == '9')
        {
            char c;
            setColor(12);
            cout << "Are you Sure you want to exit";
            cin >> c;
            setColor(7);
            if (c == 'y' || c == 'Y')
                break;
        }
    }
}
void header()
{
    cout << endl;
    cout << R"(
         /$$      /$$  /$$$$$$   /$$$$$$ 
        | $$$    /$$$ /$$__  $$ /$$__  $$
        | $$$$  /$$$$| $$  \ $$| $$  \__/
        | $$ $$/$$ $$| $$$$$$$$| $$      
        | $$  $$$| $$| $$__  $$| $$      
        | $$\  $ | $$| $$  | $$| $$    $$
        | $$ \/  | $$| $$  | $$|  $$$$$$/
        |__/     |__/|__/  |__/ \______/ 
              
              )";
    cout << endl;
    cout << "-----------------------------------" << endl;
    cout << "   Modular Arithmetic Calculator   " << endl;
    cout << "-----------------------------------" << endl;
}
/*==============GCD CALCULATION BY EUCLIDEAN=============*/

long long GCD(long long x, long long y, bool show)
{
    if (x < 0)
    {
        x = -x;
    }
    if (y < 0)
    {
        y = -y;
    }
    if (y > x)
    {
        int temp = x;
        x = y;
        y = temp;
    }
    while (y != 0)
    {
        if (show)
        {
            cout << x << " = " << y << "*" << x / y << " + " << x % y << endl;
        }
        int remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}
/*==============MERSENNE PRIMES CALCULATION=============*/
long long isMersenne(long long p)
{
    long long Mp = pow(2, p) - 1;
    return Mp;
}
bool isPrime(long long Mp)
{
    bool prime = true;
    if (Mp <= 1)
        prime = false;

    for (int i = 2; i <= sqrt(Mp); i++)
    {
        if (Mp % i == 0)
        {
            prime = false;
        }
    }
    return prime;
}
/*==============SIEVING FUNCTION CALCULATION=============*/

void sieve(int n)
{
    if (n < 2)
    {
        cout << "no primes in this range." << endl;
        pause();
        return;
    }
    bool arr[n + 1];
    for (int i = 0; i <= n; i++)
    {
        arr[i] = true;
    }
    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i * i <= n; i++)
    {

        for (int j = i * i; j <= n; j += i)
        {
            arr[j] = false;
        }
    }
    cout << "prime number up to " << n << " are: " << endl;
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (arr[i])
        {
            cout << i << " ";
            count++;
        }
    }

    cout << "\n total primes found: " << count << endl;

    history[historyCount++] = "Sieve: primes up to " + to_string(n) + " (" + to_string(count) + " primes found)";

    pause();
}
/*==============MODULAR EXPONENTIATION CALCULATION=============*/

long long modExp(long long a, long long b, long long m)
{
    long long res = 1;
    a = a % m;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b / 2;
    }
    return res;
}
/*==============EXTENDED EUCLIDEAN CALCULATION=============*/

long long EEA(long long a, long long b, long long &x, long long &y, bool show)
{
    long long x0 = 1, y0 = 0;
    long long x1 = 0, y1 = 1;
    long long a0 = a, b0 = b;

    while (b0 != 0)
    {
        long long q = a0 / b0;
        if (show)
        {
            cout << a << " = " << b << " * " << q << " + " << a % b << endl;
        }
        long long r = a0 % b0;
        long long xTemp = x0 - q * x1;
        long long yTemp = y0 - q * y1;

        x0 = x1;
        y0 = y1;
        x1 = xTemp;
        y1 = yTemp;
        a0 = b0;
        b0 = r;
    }

    x = x0;
    y = y0;
    return a0;
}
/*==============LINEAR CONGRUENCES=============*/

bool Linear(long long a, long long b, long long m, long long &x0, long long &mod, long long &count)
{
    long long g = GCD(a, m);
    if (b % g != 0)
    {
        return false;
    }
    long long a1 = a / g;
    long long b1 = b / g;
    long long m1 = m / g;
    long long inv;

    if (!modularInverse(a1, m1, inv))
    {
        return false;
    }
    x0 = (b1 * inv) % m1;
    x0 = (x0 + m1) % m1;
    mod = m1;
    count = g;

    return true;
}
/*==============CHINESE REMAINDER THEOREM=============*/

bool CRT(long long a[], long long m[], int k, long long &x, long long &mod)
{
    mod = 1;
    for (int i = 0; i < k; i++)
    {
        mod *= m[i];
    }
    cout << endl
         << "Step1. calculate M=m1*m2*.....mn" << endl;
    cout << "M= ";
    for (int i = 0; i < k; i++)
    {
        cout << m[i];
        if (i < k - 1)
            cout << " * ";
    }
    cout << " = " << mod << endl;
    long long Mi[10];
    for (int i = 0; i < k; i++)
    {
        Mi[i] = mod / m[i];
        cout << "M" << i + 1 << "=M/m" << i + 1 << " = " << mod << " / " << m[i] << " = " << Mi[i] << endl;
    }

    x = 0;
    for (int i = 0; i < k; i++)
    {
        long long modi = mod / m[i];
        long long yi, temp;
        if (!modularInverse(modi, m[i], yi))
        {
            return false;
        }
        cout << endl
             << " the steps where EEA is being applied is this";
        long long g = EEA(modi, m[i], yi, temp, true);
        x += a[i] * modi + yi;
    }
    x = (x % mod + mod) % mod;
    return true;
}
/*==============MODULAR INVERSE CALCULATION=============*/

bool modularInverse(long long a, long long m, long long &inv)
{
    long long x, y;
    long long g = EEA(a, m, x, y, true);
    if (g != 1)
        return false;
    // if inverse is negative it makes it positive and then takes mod so it is in range
    inv = (x % m + m) % m;
    return true;
}

/*==============UTILITY FUNCTIONS DEFINATION=============*/
void pause()
{
    divider();
    cout << endl
         << "press any key to continue...";
    getch();
}
void divider()
{
    cout << "\n----------------------------------------------------------------\n";
}
void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
