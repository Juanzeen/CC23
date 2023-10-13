programa
{
	
	funcao inicio()
	{
		//Programa de conversão de moedas!
		
		real valorI, taxa1 = 0.20, taxa2 =0.18, valorF
		inteiro select = 0
		cadeia enter

		escreva("Hello user, sou um programa de conversão de moedas, onde automaticamente adiciono a taxa de conversão de qualquer valor!\n")
		escreva("Fui feito para converter apenas dólar e euro, mas você pode adicionar ainda mais opções!\n")
		escreva("\nEntão vamos lá!, pressione ENTER para que possamos prosseguir com o programa ")
		leia(enter)
		limpa()

		enquanto(select!=3){
			escreva("1) Conversão de real para dólar\n")
			escreva("2) Conversão de real para euro\n")
			escreva("3) Parar programa!\n")
			escreva("Digite aqui a opção desejada: ")
			leia(select)
			limpa()

			escolha(select){

				caso 1: escreva("Digite aqui o valor que deseja converter: ")
					   leia(valorI)
					   valorF = valorI*taxa1
					   limpa()
					   escreva("O resultado da conversão foi: ",valorF,"U$3")
					   escreva("\nPressione ENTER para voltar para a tela de seleção!")
					   leia(enter)	
					   limpa()	
				pare

				caso 2: escreva("Digite aqui o valor que deseja converter: ")
					   leia(valorI)
					   valorF = valorI*taxa2
					   limpa()
					   escreva("O resultado da conversão foi: ",valorF,"£")
					   escreva("\nPressione ENTER para voltar para a tela de seleção!")
					   leia(enter)	
					   limpa()
					   
				pare

				caso 3: escreva("Programa encerrado com sucesso! Obrigado por ter testado :)")
				pare

				caso contrario: escreva("Você digitou um valor inválido, por favor siga as instruçeõs do programa.\n")
							 escreva("\nPressione ENTER para voltar para a tela de seleção.")
					   		 leia(enter)	
							 limpa()
					  
				}
			}
		
	}
}
/* $$$ Portugol Studio $$$ 
 * 
 * Esta seção do arquivo guarda informações do Portugol Studio.
 * Você pode apagá-la se estiver utilizando outro editor.
 * 
 * @POSICAO-CURSOR = 494; 
 * @PONTOS-DE-PARADA = ;
 * @SIMBOLOS-INSPECIONADOS = ;
 * @FILTRO-ARVORE-TIPOS-DE-DADO = inteiro, real, logico, cadeia, caracter, vazio;
 * @FILTRO-ARVORE-TIPOS-DE-SIMBOLO = variavel, vetor, matriz, funcao;
 */