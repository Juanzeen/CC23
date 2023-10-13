//Divisãp recursiva
/*Divisão é feita baseada em quantas vezes o número pode ser subtraído do outro*/
programa
{
	inteiro res =  0, resto = 0
	
	funcao  inteiro divisao(inteiro a, inteiro b){
		se(a-b<=0){
			escreva(res+1, "\n")
			retorne res 
			}
			
		senao{
			res = res + 1
			retorne  a - divisao(a-b, b)}
		
	}


		
	
	
	funcao inicio()
	{
		inteiro num1, num2
		
		escreva("Digite dois números: ")
		leia(num1, num2)
		se(num1==0){
			escreva("Resultado da divisão  é 0!")}
		senao se(num2 ==0){
			escreva("Não  é possível dividir por 0")}
		escreva(divisao(num1,num2))
	
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 245; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = {res, 5, 9, 3}-{a, 7, 33, 1}-{b, 7, 44, 1};
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */