#ifndef MYCONSTS_H
#define MYCONSTS_H
#define success 1
#define error 0

static char ajudaTitulo[] = "==============[AJUDA]==============\n";
static char ajudaCriar[] = "CRIAR: Comando para criar um pasta/arquivo\nsintaxe:\n1)Criar -d nome_pasta\n2)Criar -a nome_arquivo\n";
static char ajudaInserir[] = "INSERIR: Comando para inserir texto em arquivo\nsintaxe:\n1)Inserir nome_arquivo \"Seu texto!\"\n";
static char ajudaLer[] = "Ler: Comando para ler texto de um arquivo\nsintaxe:\n1)Ler nome_arquivo\n";
static char ajudaListar[] = "LISTAR: Comando para listar todos os aquivos ou diretorios de um diretorio\nsintaxe:\n1)Listar\n";
static char ajudaApagar[] = "APAGAR: Comando para apagar pasta ou arquivo\nsintaxe:\n1)Apagar nome_pasta\n2)Apagar nome_arquivo\n";
static char ajudaRenomear[] = "RENOMAR: Comando para renomear pasta ou arquivo\nsintaxe:\n1)Renomear nome_antigo nome_novo\n";
static char ajudaMover[] = "MOVER: Comando para mover pasta ou arquivo\nsintaxe:\n1)Mover nome_pasta M1000_OS\\nome_pasta\n2)Mover nome_arquivo M1000_OS\\nome_pasta\n";
static char ajudaDeletar[] = "DELETAR: Comando para deletar pasta ou arquivo\nsintaxe:\n1)Deletar nome_pasta\n2)Deletar nome_arquivo\n";
static char ajudaAjuda[] = "AJUDA: Comando par alistar todos ou somente um comando\nsintaxe:\n1)Ajuda\n2)Ajuda comando\n";
static char ajudaVer[] = "VER: Comando para ver a versao do Sistema Operacional\nsintaxe:\n1)Ver\n";
static char ajudaVerM1000[] = "VER_M: Comando para ver a versao do terminal\nsintaxe:\n1)Ver_M\n";
static char ajudaData[] = "DATA: Comando para ver a data\nsintaxe:\n1)Data\n";
static char ajudaHora[] = "HORA: Comando para ver a hora\nsintaxe:\n1)Hora\n";
static char ajudaLimpar[] = "LIMPAR: Comando para limpar a tela\nsintaxe:\n1)Limpar\n";
static char ajudaSair[] = "SAIR: Comando para sair da aplicacao\nsintaxe:\n1)Sair\n";
static char ajudaTd[] = "TD: Comando para trocar diretorio\nsintaxe:\n1)td nome_pasta\n2)td ..\n3)td ...\n";
static char ajuda404[] = "Comando nao encontrado, digite ajuda, para listar todos os comandos\n\n";

static char erroDir[] = "Diretorio nao encontrado\n\n";
static char erroPastaRepitida[] = "Essa pasta ja existe!\n\n";
static char erroArquivoRepitido[] = "Esse arquivo ja existe!\n\n";

static char erroSintaxeCriar[] = "Erro de sintaxe\nExemplo: Criar -d/-a nome\n\n";
static char erroSintaxeInserir[] = "Erro de sintaxe\nExemplo: Inserir nome_arquivo \"Seu texto\"\n\n";
static char erroSintaxeLer[] = "Erro de sintaxe\nExemplo: Ler nome_arquivo\n\n";
static char erroSintaxeListar[] = "Erro de sintaxe\nExemplo: Listar\n\n";
static char erroSintaxeApagar[] = "Erro de sintaxe\nExemplo: Apagar nome_pasta/arquivo\n\n";
static char erroSintaxeRenomear[] = "Erro de sintaxe\nExemplo: Renomear antigo_nome novo_nome\n\n";
static char erroSintaxeMover[] = "Erro de sintaxe\nExemplo: Mover arquivo/pasta M1000_OS\nome_pasta\n\n";
static char erroSintaxeDeletar[] = "Erro de sintaxe\nExemplo: Deletar nome_pasta/arquivo\n\n";
static char erroSintaxeAjuda[] = "Erro de sintaxe\nExemplo: Ajuda comando\n\n";
static char erroSintaxeVer[] = "Erro de sintaxe\nExemplo: Ver\n\n";
static char erroSintaxeVerM1000[] = "Erro de sintaxe\nExemplo: Ver_m\n\n";
static char erroSintaxeData[] = "Erro de sintaxe\nExemplo: Data\n\n";
static char erroSintaxeHora[] = "Erro de sintaxe\nExemplo: Hora\n\n";
static char erroSintaxeLimpar[] = "Erro de sintaxe\nExemplo: Limpar\n\n";
static char erroSintaxeSair[] = "Erro de sintaxe\nExemplo: Sair\n\n";
static char erroSintaxeTd[] = "Erro de sintaxe\nExemplo: td nome_pasta/../...\n\n";

#endif
