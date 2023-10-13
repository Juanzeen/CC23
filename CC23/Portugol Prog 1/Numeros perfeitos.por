programa
{
	
	funcao inicio()
	{
		//Checagem de numero perfeito

		inteiro n, cont=0
		escreva("Digite um número para verificar se ele é perfeito ou não: ")
		leia(n)
		inteiro divisores[n]
		
		para(inteiro i=1;i<n;i++){

			se(n%i==0){
				cont = cont + i
			}
		}

		se(cont==n){
			escreva("O número é perfeito!")}

		senao escreva("O número não é perfeito!")
		
		
		
		}
		
	
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 194; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */