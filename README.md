# Controle de Servo com Raspberry Pi Pico no Wokwi

Este projeto simula o controle de um servomotor usando o Raspberry Pi Pico no Wokwi. O primeiro código controla apenas o servo, enquanto o segundo código adiciona a funcionalidade de controle de um LED RGB na GPIO 12.

## Requisitos
- Conta no [Wokwi](https://wokwi.com)
- Firmware gerado a partir do código C
- Arquivo `wokwi.toml` correspondente ao código em uso

## Como Executar no Wokwi
1. Acesse o link do projeto no Wokwi:
   - **Primeiro código (somente servo):** [Adicionar Link](#)
   - **Segundo código (servo + LED RGB):** [Adicionar Link](#)
2. Faça upload do arquivo `.uf2` gerado pelo compilador Pico SDK.
3. Clique em **Start Simulation** para iniciar a simulação.

## Funcionamento dos Códigos
### Primeiro Código:
- Controla um servomotor na GPIO 22 com ciclos PWM ajustados para 0°, 90° e 180°.
- Movimenta o servo suavemente entre 0° e 180°.

### Segundo Código:
- Mesmo controle do servo da primeira versão.
- Adiciona o controle de um LED RGB na GPIO 12.
- O brilho do LED varia conforme a posição do servo.

## Vídeo Demonstrativo
- Assista ao vídeo da simulação: [Adicionar Link](#)

## Compilação e Upload
1. Compile o código usando o **Pico SDK**.
2. Gere o arquivo `.uf2` e faça upload no Wokwi.
3. Execute a simulação para validar o funcionamento.

Se precisar de ajustes, modifique o código-fonte e gere um novo `.uf2`.

