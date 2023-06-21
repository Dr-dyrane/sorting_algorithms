# Sorting Algorithms and Big O

This repository contains various sorting algorithms implemented in C.

## Table of Contents

- [Introduction](#introduction)
- [Algorithms](#algorithms)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

## Introduction

Sorting algorithms are fundamental in computer science and are used to arrange elements in a specific order. This repository provides different sorting algorithms implemented in the C programming language. Each algorithm is implemented as a separate file and can be used independently.

The following sorting algorithms are currently implemented:

- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort
- Cocktail Shaker Sort
- Counting Sort
- Merge Sort
- Heap Sort

## Algorithms

Each sorting algorithm is implemented in a separate C file within the repository. The source code is well-commented and organized for easy understanding. Additionally, the repository contains sample input files and main files to test the sorting algorithms.

Here is the list of files available in this repository:

- [bubble_sort.c](./0-bubble_sort.c): Implementation of the Bubble Sort algorithm.
- [insertion_sort.c](./1-insertion_sort.c): Implementation of the Insertion Sort algorithm.
- [selection_sort.c](./2-selection_sort.c): Implementation of the Selection Sort algorithm.
- [shell sort - Knuth Sequence](./100-shell_sort.c): Implementation of the Shell Sort algorithm.
- [quick_sort.c](./3-quick_sort.c): Implementation of the Quick Sort algorithm.
- [cocktail_shaker_sort.c](./101-cocktail_sort_list.c): Implementation of the Cocktail Shaker Sort algorithm.
- [counting_sort.c](./102-counting_sort.c): Implementation of the Counting Sort algorithm.
- [merge_sort.c](./103-merge_sort.c): Implementation of the Merge Sort algorithm.
- [heap_sort.c](./104-heap_sort.c): Implementation of the Heap Sort algorithm.
- [radix sort](./105-radix_sort.c) Implementation of the Radix Sort algorithm.
- [bitonic sort](./106-bitonic_sort.c): Implementation of the Bitcoin Sort algorithm.
- [quick Sort - Hoare Partition scheme](./107-quick_sort_hoare.c): Implementation of the Quick Sort algorithm - Hoare Partition scheme.
- [dealer](./1000-sort_deck.c) Implementation of a function that sorts a deck of cards.

## Usage

To use any of the sorting algorithms, follow these steps:

1. Clone the repository to your local machine:

   ```shell
   $ git clone https://github.com/Dr-dyrane/sorting_algorithms.git
   ```

2. Navigate to the desired algorithm's file:

   ```shell
   $ cd sorting_algorithms
   ```

3. Compile the C file using a C compiler (e.g., gcc):

   ```shell
   $ gcc -Wall -Wextra -Werror -pedantic <algorithm_file.c> -o <executable_name>
   ```

4. Execute the compiled file:
   ```shell
   $ ./<executable_name>
   ```

The program will prompt you for the input or use a predefined input array. It will then display the sorted array as output.

## Contributing

Contributions to this repository are welcome. If you find any issues or want to add new features or algorithms, please feel free to open an issue or submit a pull request. Make sure to follow the repository's code style and guidelines.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more information.

## Author

This repository is created and maintained by [Alexander Udeogaranya](https://github.com/Dr-dyrane/sorting_algorithms).
