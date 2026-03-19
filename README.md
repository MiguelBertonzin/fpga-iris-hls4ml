# Iris Classification on FPGA using hls4ml + Vitis HLS + Vivado + PYNQ-Z2

Este projeto implementa um classificador do dataset Iris em FPGA usando o fluxo:

Python → Keras → hls4ml → Vitis HLS → Vivado → PYNQ-Z2

## Objetivo
Demonstrar um hello world completo de IA em FPGA, desde o treinamento do modelo até a inferência em hardware real na placa PYNQ-Z2.

## Pipeline
1. Treinamento do modelo MLP no dataset Iris
2. Conversão do modelo com hls4ml
3. Síntese HLS no Vitis HLS
4. Integração no Vivado
5. Geração do bitstream
6. Execução na PYNQ-Z2

## Resultados principais
- Target device: xc7z020-clg400-1
- Clock target: 10 ns
- Clock estimated: 6.217 ns
- Latência: 14 ciclos
- Latência absoluta: 0.140 us
- II: 1
- LUT: 4310
- FF: 4164
- DSP: 107
- BRAM: 0
- Fmax estimada: 160.84 MHz

## Estrutura
- `model/`: treinamento e arquivos do modelo
- `hls/`: conversão hls4ml, firmware e scripts Tcl
- `pynq/`: notebook/script de inferência na placa
- `results/`: relatórios e evidências visuais

## Evidências
Adicione aqui screenshots de:
- relatório HLS
- block design no Vivado
- inferência rodando na PYNQ

## Autor
Miguel Bertonzin
