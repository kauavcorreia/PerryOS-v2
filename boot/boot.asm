[org 0x7c00]

start:

cli                     ; desabilita interrupções

xor ax, ax              ; ax = 0
mov ds, ax
mov es, ax
mov ss, ax              
mov sp, 0x7c00          ; inicializa stack

sti                     ; reativa interrupções

mov [BOOT_DRIVE], dl    ; salva o drive que a BIOS usou

mov bx, 0x1000          ; endereço onde o kernel será carregado
mov dh, 2               ; número de setores

call disk_load          ; chama rotina de leitura

jmp 0x0000:0x1000       ; executa o kernel carregado

; ------------------------
; rotina de leitura do disco
; ------------------------

disk_load:

mov si, 3               ; número de tentativas

retry:

mov ah, 0x02            ; BIOS: ler setores
mov al, dh              ; quantidade de setores

mov ch, 0               ; cilindro
mov cl, 2               ; setor (bootloader está no 1)
mov dh, 0               ; cabeça

mov dl, [BOOT_DRIVE]    ; drive correto

int 0x13

jnc disk_ok             ; se não houve erro → sucesso

dec si                  ; diminui tentativas
jnz retry               ; tenta novamente

jmp disk_error          ; se falhar 3 vezes

disk_ok:
ret

; ------------------------
; erro
; ------------------------

disk_error:

mov ah, 0x0e
mov al, 'E'
int 0x10

jmp $

BOOT_DRIVE db 0

times 510-($-$$) db 0
dw 0xaa55