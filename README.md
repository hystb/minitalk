<div align="center">
<h1 align="center">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" width="100" />
<br>minitalk
</h1>
<h3>◦ Max efficiency, minitalk powers your coding flow!</h3>
<h3>◦ Developed with the software and tools listed below.</h3>

<p align="center">
<img src="https://img.shields.io/badge/C-A8B9CC.svg?style&logo=C&logoColor=black" alt="C" />
</p>
<img src="https://img.shields.io/github/languages/top/hystb/minitalk?style&color=5D6D7E" alt="GitHub top language" />
<img src="https://img.shields.io/github/languages/code-size/hystb/minitalk?style&color=5D6D7E" alt="GitHub code size in bytes" />
<img src="https://img.shields.io/github/commit-activity/m/hystb/minitalk?style&color=5D6D7E" alt="GitHub commit activity" />
<img src="https://img.shields.io/github/license/hystb/minitalk?style&color=5D6D7E" alt="GitHub license" />
</div>

---

## 📒 Table of Contents
- [📒 Table of Contents](#-table-of-contents)
- [📍 Overview](#-overview)
- [⚙️ Features](#-features)
- [📂 Project Structure](#project-structure)
- [🧩 Modules](#modules)
- [🚀 Getting Started](#-getting-started)

---


## 📍 Overview

The mini-talk project is a client-server communication system implemented in C using signals. It allows clients to send messages to a server by converting the message size and characters into binary form and sending them as signals. The server receives the signals, reconstructs the message, and prints it. This project provides a lightweight, efficient, and easy-to-use method for inter-process communication, making it valuable for applications requiring real-time data transfer or synchronization between processes.

---

## ⚙️ Features

| Feature                | Description                           |
| ---------------------- | ------------------------------------- |
| **⚙️ Architecture**     | The codebase follows a client-server architecture, where the server listens for signals and receives messages from the client. The server and client programs are organized into separate folders, and communication is achieved using signals as a form of inter-process communication. |
| **📖 Documentation**   | The codebase lacks comprehensive documentation. The Makefile provides basic explanations of the build process, but most of the code comments are limited or absent. Clearer and more detailed documentation would improve the codebase's understandability and maintainability. |
| **🔗 Dependencies**    | The codebase relies on the standard C libraries. It also has a dependency on the custom printf library "libftprintf.a" provided in the "ft_printf" folder. These dependencies are specified in the Makefile and are necessary for building and running the code. |
| **🧩 Modularity**      | The codebase demonstrates modularity by having different functions distributed across multiple source files. Each file serves a specific purpose, such as handling signals, message processing, and I/O operations. This modular approach enhances code organization, reusability, and maintainability. |
| **✔️ Testing**          | The codebase lacks explicit testing strategies and tools. While testing could potentially be implemented separately, the lack of dedicated testing code or instructions makes it difficult to determine how thoroughly the code has been tested. Having unit tests and test coverage tools would enhance code reliability and robustness. |
| **⚡️ Performance**      | The performance of the system is difficult to assess without further testing and analysis. However, the use of signals for inter-process communication and the ability to handle messages in chunks can potentially provide efficient and optimized performance. Further profiling and benchmarking could verify the system's performance characteristics. |
| **🔐 Security**        | The codebase does not explicitly address security measures. As a signal-based communication system, there are minimal defenses against unauthorized message interception or tampering. Additional security measures could be implemented, such as encrypting the message or introducing some form of authentication between the client and server. |
| **🔀 Version Control** | The codebase uses Git for version control, as evidenced by the GitHub repository. While it lacks commit guidelines or branching strategies in the documentation, the overall version control history helps track changes, collaborate effectively, and manage project versions and releases. |
| **🔌 Integrations**    | The system does not appear to have explicit integrations with external systems or services. However, the codebase can be extended and integrated with other systems that support signal-based communication, as long as they adhere to the compatible protocols or APIs. |
| **📶 Scalability**     | The system's scalability is contingent on various factors, such as message size, network conditions, and the chosen inter-process communication mechanism. Vertical scalability can be achieved by optimizing code efficiency and reducing resource consumption. Horizontal scalability could be explored by distributing the client-server infrastructure across multiple machines or processes. The codebase provides a foundation, but further scalability measures would need to be considered depending on the desired scale and requirements. |

---


## 📂 Project Structure


```bash
repo
├── ft_printf
│   ├── ft_printf.c
│   ├── ft_printf.h
│   ├── Makefile
│   ├── switchman.c
│   └── utils
│       ├── ft_putchar_fd.c
│       ├── ft_puthex_maj.c
│       ├── ft_puthex_min.c
│       ├── ft_puthex_ptr.c
│       ├── ft_putnbr_fd.c
│       ├── ft_putnbr_unsigned.c
│       ├── ft_putstr_fd.c
│       └── ft_strlen.c
├── Makefile
├── src_client
│   ├── client.h
│   ├── main.c
│   └── utils.c
└── src_server
    ├── main.c
    ├── server.h
    └── utils.c

4 directories, 19 files
```

---

## 🧩 Modules

<details closed><summary>Root</summary>

| File                                                             | Summary                                                                                                                                                                                                                                                                                                                                                                                               |
| ---                                                              | ---                                                                                                                                                                                                                                                                                                                                                                                                   |
| [Makefile](https://github.com/hystb/minitalk/blob/main/Makefile) | This code snippet is a Makefile that compiles and builds a minitalk client and server program. It includes source files, header files, and library dependencies. The Makefile targets include "all", "clean", "fclean", and "re". The code also includes rules for compiling the source files into object files and linking all the necessary components to create the client and server executables. |

</details>

<details closed><summary>Ft_printf</summary>

| File                                                                             | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                                          |
| ---                                                                              | ---                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| [ft_printf.h](https://github.com/hystb/minitalk/blob/main/ft_printf/ft_printf.h) | This code snippet defines a header file "ft_printf.h" that contains function declarations for performing formatted printing. It includes functions for outputting characters, numbers, strings, and hexadecimal values. The main function is "ft_printf" which takes a format string and optional arguments to perform formatted printing similar to the standard printf function.                                                                               |
| [Makefile](https://github.com/hystb/minitalk/blob/main/ft_printf/Makefile)       | The code snippet provided is a makefile that compiles and links the source files to create a library called libftprintf.a. It includes various functions in the utils folder that perform tasks like outputting characters, hexadecimal numbers, integers, and strings. The makefile also has commands to clean, remove, and recompile the library. The overall purpose of the code is to provide commonly used formatting functions for printing in C programs. |
| [ft_printf.c](https://github.com/hystb/minitalk/blob/main/ft_printf/ft_printf.c) | The provided code is a function called "ft_printf" that takes in a string format and optional arguments. It iterates through the format string, processing the format specifiers and printing the corresponding values. It uses a va_list and a switch statement to handle different format specifiers. The function returns the total number of characters printed.                                                                                             |
| [switchman.c](https://github.com/hystb/minitalk/blob/main/ft_printf/switchman.c) | The provided code snippet defines the function "switchman" which takes a format specifier character and an argument list as input. It then performs different actions based on the provided format specifier, such as printing characters, strings, numbers, or hexadecimal values. If the input is not recognized, it writes the format specifier character as is. This function is part of a larger program that implements a custom printf function.          |

</details>

<details closed><summary>Utils</summary>

| File                                                                                                     | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| ---                                                                                                      | ---                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [ft_putnbr_fd.c](https://github.com/hystb/minitalk/blob/main/ft_printf/utils/ft_putnbr_fd.c)             | The code defines a function ft_putnbr_fd that takes an integer and a file descriptor as inputs. It converts the integer to a string and writes it to the specified file descriptor. The function handles positive, negative, and zero integers correctly, including the special case of the minimum integer value.                                                                                                                      |
| [ft_puthex_min.c](https://github.com/hystb/minitalk/blob/main/ft_printf/utils/ft_puthex_min.c)           | The code snippet is a function called ft_puthex_min that takes in an unsigned long number as input and prints its hexadecimal representation to the console. It handles both positive and negative numbers, as well as the case when the input is zero. The function makes use of helper functions to reverse the order of digits in the hexadecimal representation and to print strings and characters to a specified file descriptor. |
| [ft_putchar_fd.c](https://github.com/hystb/minitalk/blob/main/ft_printf/utils/ft_putchar_fd.c)           | The code snippet provides a function, ft_putchar_fd, which writes a single character to a file descriptor given as an argument. This function is a part of the ft_printf library. It returns the number of characters written.                                                                                                                                                                                                          |
| [ft_puthex_ptr.c](https://github.com/hystb/minitalk/blob/main/ft_printf/utils/ft_puthex_ptr.c)           | The code snippet defines a function "ft_puthex_ptr" that converts a pointer address into a hexadecimal string. It takes a void pointer as input and outputs the hexadecimal representation of the address. If the pointer is null, it returns zero, otherwise, it converts the address into hexadecimal and writes it to the standard output.                                                                                           |
| [ft_putnbr_unsigned.c](https://github.com/hystb/minitalk/blob/main/ft_printf/utils/ft_putnbr_unsigned.c) | The code snippet defines a function "ft_putnbr_unsigned" that takes an unsigned integer and a file descriptor as input. It converts the integer into a string and writes it to the given file descriptor. If the integer is negative, it includes a'-' symbol in the string. If the integer is zero, it writes'0' to the file descriptor. If the integer is invalid (null), it returns an error message.                                |
| [ft_putstr_fd.c](https://github.com/hystb/minitalk/blob/main/ft_printf/utils/ft_putstr_fd.c)             | The provided code snippet defines a function "ft_putstr_fd" that writes a string to a specified file descriptor. If the input string is NULL, it writes "(null)" to the file descriptor. Otherwise, it writes the string and returns the number of characters written.                                                                                                                                                                  |
| [ft_puthex_maj.c](https://github.com/hystb/minitalk/blob/main/ft_printf/utils/ft_puthex_maj.c)           | The code snippet is a function that converts a given decimal number into a hexadecimal representation (uppercase). It utilizes recursion to divide the number by 16 and convert the remainders into hexadecimal characters. The function also handles negative numbers, as well as zero, and outputs the result to the standard output.                                                                                                 |
| [ft_strlen.c](https://github.com/hystb/minitalk/blob/main/ft_printf/utils/ft_strlen.c)                   | The code defines a function named ft_strlen which calculates the length of a given string (terminated by null character'\0'). It iterates through the characters of the string and counts the number of characters until the null character is encountered. The resulting count is returned as the length of the string.                                                                                                                |

</details>

<details closed><summary>Src_server</summary>

| File                                                                        | Summary                                                                                                                                                                                                                                                                                                                                                                             |
| ---                                                                         | ---                                                                                                                                                                                                                                                                                                                                                                                 |
| [server.h](https://github.com/hystb/minitalk/blob/main/src_server/server.h) | The provided code snippet is a header file for a server program. It includes libraries for signals, memory allocation, and I/O, as well as a custom header file for printf functionality. It declares function prototypes for receiving a message, allocating memory for a message, getting the size of a message, getting a message by signal, and resetting the end of a message. |
| [utils.c](https://github.com/hystb/minitalk/blob/main/src_server/utils.c)   | This code snippet defines a'reset_end_message' function that takes a character array, an integer pointer, a boolean pointer, and an integer size as parameters. The function resets the character array, sets the integer pointer to zero, and assigns the boolean pointer to 3 if the integer pointer reaches the given size.                                                      |
| [main.c](https://github.com/hystb/minitalk/blob/main/src_server/main.c)     | This code snippet is a server implementation that listens for signals and receives a message. Upon receiving the signals, it determines the size of the message, allocates memory for the message, and then receives the individual characters of the message. Finally, it prints the received message.                                                                             |

</details>

<details closed><summary>Src_client</summary>

| File                                                                        | Summary                                                                                                                                                                                                                                                                                                                                                                                                                                 |
| ---                                                                         | ---                                                                                                                                                                                                                                                                                                                                                                                                                                     |
| [utils.c](https://github.com/hystb/minitalk/blob/main/src_client/utils.c)   | The code snippet provides utility functions for validating and converting strings to integers. The "is_int" function checks if a string represents a valid integer within a given range and format. The "ft_atoi" function converts a string to a long integer, handling negative sign and overflow cases. The "ft_strlen" function computes the length of a string.                                                                    |
| [client.h](https://github.com/hystb/minitalk/blob/main/src_client/client.h) | The code provides the header file for a client program. It includes various libraries and declares several functions: "send_size" to send the size, "send_message" to send a message, "is_int" to check if a string is an integer, "ft_atoi" to convert a string to an integer, and "ft_strlen" to calculate the length of a string.                                                                                                    |
| [main.c](https://github.com/hystb/minitalk/blob/main/src_client/main.c)     | The provided code is a client program that sends a message to a server using signals. It takes two command line arguments: the server's process ID and the message to be sent. It checks for the correct number of arguments, converts the message size into binary and sends it to the server using the SIGUSR1 and SIGUSR2 signals. Then, it sends each character of the message to the server in binary form using the same signals. |

</details>

---

## 🚀 Getting Started

### 📦 Installation

1. Clone the minitalk repository:
```sh
git clone https://github.com/hystb/minitalk
```

2. Change to the project directory:
```sh
cd minitalk
```

3. Install the dependencies:
```sh
make
```

### 🎮 Using minitalk

```sh
./client
```
```sh
./server
```
---
