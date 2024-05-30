// Given are the two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. Find the length of the shortest transformation sequence from startWord to targetWord.

// In this problem statement, we need to keep the following conditions in mind:

// A word can only consist of lowercase characters.
// Only one letter can be changed in each transformation.
// Each transformed word must exist in the wordList including the targetWord.
// startWord may or may not be part of the wordList

// Note:  If there’s no possible way to transform the sequence from startWord to targetWord return 0.

// Input:
// wordList = {"des","der","dfr","dgt","dfs"}
// startWord = "der", targetWord = "dfs"
// Output:
// 3
// Explanation: 
// The length of the smallest transformation sequence from "der" to 
// "dfs" is 3 i.e. "der" -> (replace ‘e’ by ‘f’) -> "dfr" -> (replace ‘r’ by ‘s’)  -> "dfs". 
// So, it takes 3 different strings for us to reach the targetWord. Each of these strings are present in the wordList.
