<img atl="Trabalho 01" src="../img/Capa_T1.png"/>

## Arquivo de Dados

**Este trabalho tem como objetivo armazenar dados em um arquivo binário, bem como desenvolver funcionalidades para a manipulação desses dados.**

A disciplina de Estrutura de Dados III é uma disciplina fundamental para a disciplina de Bases de Dados. A definição deste primeiro trabalho prático é feita considerando esse aspecto, ou seja, o projeto é especificado em termos de várias funcionalidades, e essas funcionalidades são relacionadas com as funcionalidades da linguagem SQL (Structured Query Language), que é a linguagem utilizada por sistemas gerenciadores de banco de dados (SGBDs) relacionais. As características e o detalhamento de SQL serão aprendidos na disciplina de Bases de Dados. Porém, por meio do desenvolvimento deste trabalho prático, os alunos poderão entrar em contato
com alguns comandos da linguagem SQL e verificar como eles são implementados.

SQL é caracterizada por ser uma linguagem de definição de dados (DDL) e uma linguagem de manipulação de dados (DML). Comandos DDL são aqueles definidos utilizando, por exemplo, CREATE, DROP e ALTER. Comandos DML são aqueles definidos utilizando SELECT, INSERT, DELETE e UPDATE. Alguns desses
comandos estarão presentes ao longo da especificação deste trabalho.

***Os trabalhos práticos têm como objetivo armazenar e recuperar dados relacionados à topologia de rede da Internet. Esses dados são reais, obtidos do
projeto intitulado Internet Tolopogy [Zoo](http://topology-zoo.org/).***

### Descrição Pagina de Disco

No trabalho será usado o conceito de páginas de disco. Cada página de disco tem o tamanho fixo de 960 bytes. Como pode ser observado, o tamanho da página de disco adotado neste trabalho é lógico, sendo adaptado de acordo com os registros de dados
do trabalho.

### Descrição Arquivo de Dados TopologiaRede

Um arquivo de dados possui um registro de cabeçalho e 0 ou mais registros de dados. A descrição do registro de cabeçalho é feita conforme a definição a seguir.

**Registro de Cabeçalho.** O registro de cabeçalho deve conter os seguintes campos:

 * __*status*__: indica a consistência do arquivo de dados, devido à queda de energia, travamento do programa, etc. Pode assumir os valores ‘0’, para indicar que o arquivo de dados está inconsistente, ou ‘1’, para indicar que o arquivo de dados está consistente. Ao se abrir um arquivo para escrita, seu status deve ser ‘0’ e, ao finalizar o uso desse arquivo, seu status deve ser ‘1’ – tamanho: string de 1 byte.

 * __*topo*__: armazena o RRN de um registro logicamente removido, ou -1 caso não haja registros logicamente removidos – tamanho: inteiro de 4 bytes.

 * __*proxRRN*__: armazena o valor do próximo RRN disponível. Deve ser iniciado com o valor ‘0’ e ser incrementado quando necessário – tamanho: inteiro de 4 bytes.

 * __*nroRegRem*__: armazena o número de registros logicamente marcados como removidos. Deve ser iniciado com o valor ‘0’ e deve ser atualizado sempre que
necessário – tamanho: inteiro de 4 bytes.

 * __*nroPagDisco*__: armazena o número de páginas de disco ocupadas pelo arquivo de dados, de acordo com a definição de página de disco feita neste trabalho. Deve ser iniciado com o valor ‘0’ e deve ser atualizado sempre que necessário –
tamanho: inteiro de 4 bytes.

 * __*qttCompacta*__: indica a quantidade de vezes que o arquivo de dados foi compactado. Deve ser iniciado com o valor ‘0’ e deve ser atualizado sempre que
a funcionalidade de compactação for solicitada – tamanho: inteiro de 4 bytes.

**Representação Gráfica do Registro de Cabeçalho.** O tamanho do registro de cabeçalho deve ser o de uma página de disco, representado da seguinte forma:

![Representação Gráfica do Registro de Cabeçalho](img/RegistroCabecalho_Com_Fundo.png)

**Observações Importantes**:

 * O registro de cabeçalho deve seguir estritamente a ordem definida na sua representação gráfica.

 * Os campos são de tamanho fixo. Portanto, os valores que forem armazenados não devem ser finalizados por '\0'.

 * O registro de cabeçalho deve ocupar uma página de disco. Portanto, descontando os campos de tamanho fixo definidos para o registro de cabeçalho, o espaço que sobra deve ser preenchido com o valor ‘ \$’, o qual representa lixo.

**Registros de Dados.** Os registros de dados são de tamanho fixo, com campos de tamanho fixo e campos de tamanho variável. Para os campos de tamanho variável, deve ser usado o método delimitador entre campos. O delimitador é o caractere ‘|’. Os campos de tamanho fixo são definidos da seguinte forma:

 * __*idConecta*__: código identificador do ponto de presença (PoPs) – inteiro – tamanho: 4 bytes. Não pode assumir valores nulos. Pode ter valores repetidos.

 * __*siglaPais*__: sigla do país no qual o PoPs está cadastrado – string – tamanho: 2 bytes. Pode assumir valores nulos. Pode ter valores repetidos.

 * __*idPoPsConectado*__: código identificador do PoPs conectado – tamanho: 4 bytes. Pode assumir valores nulos. Pode ter valores repetidos.
 * __*unidadeMedida*__: unidade de medida da velocidade de transmissão – tamanho: string de 1 byte. Pode assumir valores nulos. Pode ter valores repetidos.

 * __*velocidade*__: velocidade de transmissão – inteiro – tamanho: 4 bytes. Pode assumir valores nulos. Pode ter valores repetidos.

Os campos de tamanho variável são definidos da seguinte forma:

* __*nomePoPs*__: nome do PoPs: string. Pode assumir valores nulos. Pode ter valores repetidos.

 * __*nomePais*__: nome do país por escrito – string. Pode assumir valores nulos. Pode ter valores repetidos.

Adicionalmente, os seguintes campos de tamanho fixo também compõem cada registro. Esses campos de controle são necessários para o gerenciamento de registros logicamente removidos.  

* __*removido*__: indica se o registro está logicamente removido. Pode assumir os valores ‘1’, para indicar que o registro está marcado como logicamente removido, ou ‘0’, para indicar que o registro não está marcado como removido. – tamanho: string de 1 byte.

* __*encadeamento*__: armazena o RRN do próximo registro logicamente removido – tamanho: inteiro de 4 bytes. Deve ser inicializado com o valor -1 quando
necessário.

Os dados são fornecidos juntamente com a especificação deste trabalho prático por meio de um arquivo .csv, sendo que sua especificação está disponível na página da disciplina. No arquivo .csv, o separador de campos é vírgula (,) e o primeiro registro especifica o que cada coluna representa (ou seja, contém a descrição do conteúdo das
colunas).

**Representação Gráfica dos Registros de Dados.** O tamanho dos registros de dados deve ser de 64 bytes. Cada registro de dados deve ser representado da seguinte forma:

![Representação Gráfica dos Registros de Dados](img/RegistroDados_Com_Fundo.png)

**Observações Importantes**: 
 * Cada registro de dados deve seguir estritamente a ordem definida na sua representação gráfica.

 * As strings de tamanho variável são identificadas pelo seu tamanho e, portanto, não devem ser finalizadas com ‘\0’.

 * Os valores nulos nos campos de tamanho fixo devem ser manipulados da seguinte forma. Os valores nulos devem ser representados pelo valor -1 quando forem inteiros ou devem ser totalmente preenchidos pelo lixo ‘ \$’ quando forem do tipo string.

 * Os valores nulos nos campos de tamanho variável devem ser manipulados da seguinte forma: deve ser armazenado apenas o delimitador ‘|’.

 * Deve ser feita a diferenciação entre o espaço utilizado e o lixo. Sempre que houver lixo, ele deve ser identificado pelo caractere ‘ \$’. Nenhum byte do registro deve permanecer vazio, ou seja, cada byte deve armazenar um valor válido ou ‘ \$’.

 * Não existe a necessidade de truncamento dos dados. O arquivo .csv com os dados de entrada já garante essa característica.

 * Os registros de dados não devem ser armazenados na mesma página de disco que o registro de cabeçalho. Adicionalmente, os registros de dados devem ser armazenados em várias páginas de disco, de acordo com a quantidade de registros gerados.


# Autores

<table>
  <tr align="center">
    <td>
      <a alt="nicholasestevao GitHub" href="https://github.com/nicholasestevao">
      <img src="https://github.com/nicholasestevao.png" width=80>
      <br>
      <sub>Nicholas Estevão</sub>
      </a>
    </td>
    <td>
      <a alt="ISS2718 GitHub" href="https://github.com/ISS2718">
        <img src="https://github.com/ISS2718.png" width=80>
        <br>
        <sub>Isaac Soares</sub>
      </a>
    </td>
  </tr>
</table>

 # License
 
[MIT License](https://github.com/nicholasestevao/TrabalhosEDIII/blob/master/LICENSE) © [nicholasestevao](https://github.com/nicholasestevao)