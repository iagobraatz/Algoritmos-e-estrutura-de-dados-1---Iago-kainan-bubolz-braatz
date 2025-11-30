# Exercício prático 2 de AED1
 
**Nome: Iago Kainan Bubolz Braatz**

**Disciplina: Algoritmos e Estruturas de Dados I**

**Matrícula: 24103478**

**Turma: M2**
 
**Instituição de Ensino: Universidade Federal de Pelotas**

**Exercicio finalizado em aula**

# Exercício: LeetCode: 143. Reorder List

## Descrição do Exercício:
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.
Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:

The number of nodes in the list is in the range [1, 5 * 104].
1 <= Node.val <= 1000

Minha maior dificuldade ao realizar o exercício foi construir a lógica necessária para aplicar o algoritmo corretamente. 
Primeiro, tinha que encontrar uma forma de identificar o meio da lista usando dois ponteiros; depois, entender como inverter a segunda metade sem perder nenhuma referênci.
E por fim, intercalar as duas partes nó por nó, garantindo que os “next” fossem ajustados na ordem certa. 
Essas três etapas exigiram bastante cuidado com os ponteiros, e foi isso que acabou deixando o exercício mais complicado de fazer.

Testes feitos
Entrada (lista original) ............Saída (lista reordenada)                                                                                                                                                        
1 2 3 4..............................1 4 2 3                                                                                                                             
1 2 3 4 5............................1 5 2 4 3                                                                                                                                                    
10 20................................10 20                                                                                                                  
7....................................7                                                                                                                                                 
1 2 3 4 5 6..........................1 6 2 5 3 4                                                                                                                               
3 8 9 15 21 30 42....................3 42 8 30 9 21 15                                                                                                                         
5 7 9 11 13 15 17 19.................5 19 7 17 9 15 11 13                                                                                                                       

## Realização do exercício:
[Reorder List - Iago Kainan Bubolz Braatz](https://leetcode.com/problems/reorder-list/submissions/1841999913)
