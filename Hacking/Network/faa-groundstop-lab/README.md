# Reconstruccion en Packet tracer del mecanismo reportado en el _ground stop_ nacial del 13 de noviembre de 2026 - EEUU y comparacion controlada con un ataque de inundacion hipotetico.

**Tesis:** El sintoma del fallo real y el de un flood externo son indistinguibles desde fuera de la topologia. Por eso el **ciberataque** fue la hipotesis inicial razonable y por eso se tardo en descartarlo. La diferencia no esta en el sintoma, esta en el origen y en el metodo de corrreccion: un bucle se corrige con una linea de configuracion, un flood se combate bloqueando trafico.

**Esto es una reconstruccion: modelo el mecanismo reportado, no la red real de la FAA _(FTI)_**.

Todo lo que hay aqui cumple esta regla. Cuando una afirmacion viene de prensa esta citada en `fuentes.md`. Cuando viene de mi modelo esta marcada como modelado propio. Cuando no lo se, lo digo.

## Estado

| Lab                | Pregunta a responder                                          | Estado    |
| ------------------ | ------------------------------------------------------------- | --------- |
| a-topologia        | Como se veina la topologia antes del error/ataque?            | OK        |
| b-error-migracion  | Como se ve un bucle de enrutamiento y porque mata el paquete? | En curso  |
| a-flood            | Como se ve un ataque de flood?                                | PENDIENTE |
| b-inyeccion-ruta   | Como se ve un ataque de inyeccion de ruta?                    | PENDIENTE |
| comparacion (File) | Que indicador separa los dos casa ataque/mala-configuracion   | PENDIENTE |

## Estructura

```bash
faa-groundstop-lab/
|------ README.md
|------ 01-lab-reproduccion/
|     |---- configs/
|     |---- notas.md
|     |---- a-topologia.pkt
|     |---- b-error-migracion.pkt
|------ 02-lab-ataque-hipotetico/
|     |---- configs/
|     |---- notas.md
|     |---- a-flood.pkt
|     |---- b-inyeccion-ruta.pkt
|------ 03-lab-comparativo/
|     |---- tabla_comparativa.md
|     |---- capturas/
|------ fuentes.md
|------ capturas/
```

## Alcance: Lo que este repo no demuestra

- **La topologia no es la red de la FAA:** La FTI tiene cientos de nodos. Mi topologia tiene 3 routers y 2 switches. _Es un modelo del mecanismo, no un map_.
- **Packet Tracer no simula carga real:** Los contadores de paquetes son reales; las tasas de bits por segundo son una aproximacion que la propia herramienta calcula mal. Todo pps de este repo esta medido a mano con dos lecturas separadas, y asi esta anotado.
- **No hay convergencia de protocolo:** El bucle del Lab 1 fase 2 es de rutas estaticas, no de un protocolo dinamico. Un bucle por reinyeccion de rutas redistribuidas se comporata distinto y eso sera modelado en el Lab 2 fase b.
- **No hay una capa fisica:** El "cable de cobre" es un enlace serial en PT. No modela atenuacion, ruido, ni crimpado. Que el incidente real ocurriera durante una migracion de cobre a fibras es contexto, no algo que este repo reproduzca.
- **No hay CPU:** El agotamiento de la CPU del router es la causa mas citada de floods que tumban un control plane. PT no lo modela.
- **Los tiempos son inventados:** La duracion del fallo, los timeouts y la ventana de indisponibilidad son aproximaciones narrativas.
- **La causa raiz sigue abierta:** Los reportes hablan de un flood durante un mantenimiento. Puede ser firmware, configuracon o un latiguillo mal crimpado. Este repo no cierra esa pregunta y no lo presenta como cerrada.
- **Nada de esto es evidencia forense.:** Es un analisis practico.

## Alcance: Lo que si demuestra

- **Bucle de enrutamiento:** Que un bucle de enrutamiento provoca exactamente el mismo sintoma externo que una saturacion por flood: ping muerto, TTL agotado, servicio ciego.
- **TTL:** El TTL es el discriminante mas limpio entre: "se descarta por expiracion" y "se descarta por cola llena".
- **Configuracion y Ataque:** Que quitar el atacante y quitar una linea de configuracion producen dos resultados distintos y distinguibles.
- **Intranet:** Que no hace falta ningu origen externo para tumbar un enlace.

## Laboratorios:

- [Lab 1](01-lab-reproduccion/notas.md)
- [Lab 2](02-lab-ataque-hipotetico/notas.md)
- [Lab 3](03-lab-comparativo/tabla_comparativa.md)
