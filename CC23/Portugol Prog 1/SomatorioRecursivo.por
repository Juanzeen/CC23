programa
{
	
	//Somatório com Recursividade
	funcao inteiro soma(inteiro a, inteiro b){
		
		se(b-1==a){
		retorne 0 
		}

		senao{
		
		retorne b-1 + soma(a,b-1)}
		
		}
	
	funcao inicio()
	{
	inteiro num1, num2
	leia(num1,num2)
	enquanto(num1>num2){
		escreva("O primeiro número deve ser menor que o segundo! Digite novamente: ")
		leia(num1)
		}
	se(num1==num2){
		escreva("Não tem somatório!")}
		
	escreva(soma(num1,num2))
	
}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 395; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */