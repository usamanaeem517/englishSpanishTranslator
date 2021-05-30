# englishSpanishTranslator

## Problem
<p>You are asked to build a Spanish-English translator, storing the dictionary words using a single ordered binary tree, in which each
node will have the following information:</p>
● The word in English </br>
● The word in Spanish </br>
● A pointer to the left, right, and parent child of the node in the English word tree. </br>
● A pointer to the left, right, and parent child of the node in the Spanish word tree. </br>
In this way, in each node there will be two strings and 6 pointers that allow you to go through the tree of words in English or Spanish
depending on what you want to do. </br>
Entry: </br>
The program must be able to load the dictionary from a plain text file, which will have the Spanish word and the English translation on
each line of the file. </br>
An input file called "translator.in" will be delivered, which corresponds to two columns of words, where the first column corresponds to
the word in Spanish, and the second column corresponds to the word in English. The program must be able to add each of the words
to the ordered binary tree. An example of this file is shown below. </br>
