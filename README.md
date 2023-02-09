Geant4 simulation of an alpha particle inside an aluminum box (which is actually the world)

To compile,

```
cmake -B build -S . 
cmake --build build 
```

To run,
```
./build/main
```

A file called output.txt will be generated. It contains energy deposition dE at every step and the sum of the dE at the end. For 1 MeV alpha, there is 1 step. For 10 MeV, 1800 steps, for 1 GeV 170k steps.

Tracks of alpha are very small, so zoom is needed in order to visualize them.

Original files taken from Curso de Tecnicas Experimentales Avanzadas en Fisica nuclear, https://indico.ific.uv.es/event/6462/contributions/17067/