# Defined

Defined is a command line tool for defining words offline. It uses the [wordset-dictionary](https://github.com/wordset/wordset-dictionary) to get its data.

# Install

- To install the defined you have to have make installed. once make is installed clone the repository.

```bash
git clone https://github.com/duckisam/Defined.git
```
- Then go into change your directory to the new one made.

```bash
cd Defined
```
- Then clone the [wordset-dictionary](https://github.com/wordset/wordset-dictionary)

```bash
git clone https://github.com/wordset/wordset-dictionary.git
```
- Then make the program still in Defined directory.
```bash
make
```
- Then you will have to add the Defined/bin directory to your environment variables.

# Usage
To use defined type defined into the command line followed by the word you want defined.
```bash
defined hello #would give the first definition of the word 'hello'
```
**Flags:**

flags are used when you want more information then just the definition.
Valid Flags are:

- 's' for synonyms.
- 'e' for an example.
- 'p' for the part of speech.

you can also give a number to give a different meaning of the word.


**Valid uses**

```bash
defined bad 1 -s #gives the second definition of the word 'bad' a long with its synonyms.
```
```bash
defined python 3 -p #gives the fourth definition of the word 'python' and what part of speech it is
```
You can also flip the order of the number and the flags.

```bash
defined hello -e 0 #gives the first definition of the word 'hello' and an example.
```
flags must be given all at once.

```bash
defined pragmatic -sep #will give a synonym, an example, and the part of speech in that order.
```

# invalid usage 

splitting up flags

```bash 
defined polymorphism -s -e #this will cause an error because the flags are separated.
```
# Notes
This is my first cpp program but it does sorta work so use it if you like. 

**Note** could not get to work on linux might try again later.
