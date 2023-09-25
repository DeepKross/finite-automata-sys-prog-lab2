# 🤖 Finite Automaton Simulator 🤖

A high-performance, versatile Finite Automaton Simulator implemented in C. It reads automaton configurations from a file, evaluates the input string, and decides whether the automaton accepts the string or not.

## 🚀 Features
- 📚 Reads automaton configurations from a file.
- 🌐 Supports any valid finite automaton.
- 🔍 Evaluates and decides whether the input string is accepted or not.
- 🛠 Easy to modify and extend.

## 🛠️ Usage

Good luck)0)

# 📄 Example of File Input

```
3
4
0
2 1 3
0 a 1
0 b 2
1 c 3
2 b 1
3 a 3
```

# 🎉 Example of Program Execution

```
Enter the filename: filename.txt
Enter the word w0: abc
The automaton accepts the word abc
```

## 📝 How It Works

### Automaton Structure
The automaton is stored in a structure containing:

- The start state.
- An array of final states.
- The transition function represented as a 2D array.
- The number of states.

### Automaton Reading
The automaton is read from a file with a specific format, and the transition function is filled accordingly.

### Word Evaluation
The program evaluates whether a given word is accepted by the automaton using the transition function.

### Memory Management
The program cleans up the allocated memory before it exits.

## 📘 Code Structure
The `read_automaton` function reads the automaton configuration from a given file.
The `accepts_word_w` function evaluates whether the automaton accepts a given word or not.
The `main` function interacts with the user and orchestrates the program flow.

## 💡 Contribution
Feel free to fork 🍴 and contribute to this project by creating pull requests, or you can open an issue if you find something that you want to be added or optimized.

## 📃 License
This project is open source and available under the MIT License.

## 🤝 Acknowledgements
Big thanks to all contributors and users! Let's make learning automata theory fun and accessible! 🎉