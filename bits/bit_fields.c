#include <stdio.h>

// definição da struct com bit fields
struct file_permissions {
    unsigned int owner_read : 1;    // 1 bit para leitura do proprietário
    unsigned int owner_write : 1;   // 1 bit para escrita do proprietário
    unsigned int owner_execute : 1; // 1 bit para execução do proprietário

    unsigned int group_read : 1;    // 1 bit para leitura do grupo
    unsigned int group_write : 1;   // 1 bit para escrita do grupo
    unsigned int group_execute : 1; // 1 bit para execução do grupo

    unsigned int others_read : 1;   // 1 bit para leitura de outros
    unsigned int others_write : 1;  // 1 bit para escrita de outros
    unsigned int others_execute : 1;// 1 bit para execução de outros
};

// função para exibir as permissões
void print_permissions(struct file_permissions perms) {
    printf("Permissões do arquivo:\n");
    printf("Proprietário: %c%c%c\n",
           perms.owner_read ? 'r' : '-',
           perms.owner_write ? 'w' : '-',
           perms.owner_execute ? 'x' : '-');
    printf("Grupo: %c%c%c\n",
           perms.group_read ? 'r' : '-',
           perms.group_write ? 'w' : '-',
           perms.group_execute ? 'x' : '-');
    printf("Outros: %c%c%c\n",
           perms.others_read ? 'r' : '-',
           perms.others_write ? 'w' : '-',
           perms.others_execute ? 'x' : '-');
}

int main() {
    // definindo permissões para um arquivo
    struct file_permissions perms = {
        .owner_read = 1,
        .owner_write = 1,
        .owner_execute = 0,
        .group_read = 1,
        .group_write = 0,
        .group_execute = 1,
        .others_read = 1,
        .others_write = 0,
        .others_execute = 0
    };

    print_permissions(perms);

    printf("Tamanho da struct: %zu bytes\n", sizeof(perms));

    return 0;
}