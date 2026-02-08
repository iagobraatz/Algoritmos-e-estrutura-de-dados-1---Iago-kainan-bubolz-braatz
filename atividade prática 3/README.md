Exercício prático 3 de AED1
Nome: Iago Kainan Bubolz Braatz

Disciplina: Algoritmos e Estruturas de Dados I

Matrícula: 24103478

Turma: M2

Instituição de Ensino: Universidade Federal de Pelotas

Exercicio finalizado em aula

Exercício: LeetCode: 109. Convert Sorted List to Binary Search Tree
Descrição do Exercício:
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.

Example 1:
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:
Input: head = []
Output: []
Constraints:
The number of nodes in head is in the range [0, 2 * 104].
-105 <= Node.val <= 105
Minha maior dificuldade ao realizar o exercício foi pensar em como encontrar o elemento do meio da lista de forma correta usando dois ponteiros e controlar o intervalo com inicio e fim sem quebrar a lista.

Testes feitos
Entrada (lista ordenada).............Saída (BST)
-10 -3 0 5 9..............................0 -3 9 -10 null 5
1 2 3 4 5................................3 2 5 1 null 4
1 2 3 4..................................3 2 4 1
10 20....................................20 10
7.........................................7
1 2 3 4 5 6..............................4 2 6 1 3 5
3 8 9 15 21 30 42.....................15 8 30 3 9 21 42
5 7 9 11 13 15 17 19................11 7 15 5 9 13 17 null null null null null null null 19
(vazia)...................................[]

Realização do exercício:
[109. Convert Sorted List to Binary Search Tree - iago braatz](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/submissions/1910578291)
