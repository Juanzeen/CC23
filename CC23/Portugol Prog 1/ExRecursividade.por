//Operaçeõs recursivas
programa
{
		inteiro res = 0
		//Multiplicação = somas sucessivas
		//Logo, precisamos desmembrar a divisão em várias somas
		//A condição de parada é quando o índice da multiplicação chegar em 1
		//Pois todo número vezes um é ele mesmo
		funcao inteiro mult (inteiro a, inteiro b){
		se(b == 1){
			retorne a}

		senao{
			retorne a + mult(a, b-1) }
		}

		//Fibonacci = Soma dos dois números antecessores
		//Os dois primeiros valores são fixos, logo serão nossa condição de parada
		//Chamamos nossa funão duas vezes com uma soma, da posição -2  com a posição -1

		funcao inteiro fibonacci(inteiro pos){
			se(pos == 1){
				retorne 0}
			senao se(pos == 2){
				retorne 1}
			senao{
				retorne fibonacci(pos-2) + fibonacci(pos-1)}
			}

		//Fatorial = Pegar o número e multiplicar ele até que chegue em 1
		//A condição de parada mais viável é quando chegarmos em 0! Pois é a mesma coisa que 1
		//Logo, nossa função pode ser feita da seguinte maneira: num * fatorial(num-1)
		funcao inteiro fatorial(inteiro num){
			se(num ==0){
			retorne 1}

			senao{
			retorne num * fatorial(num-1)
			}
		}

		//Divisão = quantas vezes o denominador pode ser subtraído no numerador
		//A divisão de inteiros se encerra quando não é possível subtrair mais
		//Esse caso é quando o resto é zero ou quando a próxima subtração tiver resultado negativo
		//Na hora da recursividade o valor de a vai diminuir e o b de se mantém fixo
		funcao inteiro divisao(inteiro a, inteiro b){
			se(a-b<=0){
				retorne res++
				
				}

			senao{
				res++
				retorne a - divisao(a-b, b) }

				}
			

			
	
	funcao inicio()
	{

		inteiro num1, num2
		leia(num1, num2)
		escreva("\n---------Multilpicação---------\n")
		escreva("\t    ",mult(num1,num2))
		escreva("\n---------Fibonaci---------\n")
		escreva("\t    ",fibonacci(mult(num1,num2)))
		escreva("\n---------Fatorial---------\n")
		escreva("\t    ",fatorial(fibonacci(mult(num1,num2))))
		escreva("\n---------Divisão---------\n")
		divisao(num1,num2)
		escreva("\t    ",res)
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 1550; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {res, 4, 10, 3}-{a, 46, 33, 1}-{b, 46, 44, 1};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */