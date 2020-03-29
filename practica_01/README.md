# Pràctica 1 de IA

En aquesta pràctica experimentarem amb AIMA per tal de resoldre un problema de distribució de fitxers en un conjunt de servidors, juntament amb els usuaris que volen accedir als respectius fitxers

#### Estructura:

libs --> frameworks i llibreries necessaries

src --> codi font de la pràctica

docs --> documentació de la pràctica

enunciat.pdf --> enunciat de la pràctica

make.sh --> executable per compilar el projecte automàticament

Manifest.txt --> informació necessaria per compilar el jar final

#### Compilació i execució:

`chmod +x make.sh`

`./make.sh`

`1`

Usage: java -jar practica_01.jar seed nServers nRepetitions nUsers nRequests algorithm initialState successorFunction heuristic

seed, nServers, nRepetitions, nUsers, nRequests are int numbers

algorithm:
* hc --> HillClimbing
* sa --> SimulatedAnnealing

initialState:
* state1 --> assign each request to the server with less delay
* state2  --> for random assignation

successorFunction (operator)
* op1    --> moveMaxFile: moves slowest file from lowest server
* op2    --> moveRandomFile: a random server is selected, and the file at its peak is moved to all others
* op3    --> combination: op1 + op2
* op4    --> combination: op1 intersection op2

heuristic:
* best          --> take into account maxTransmissionTime & std from all servers
* slowestServer --> only checks MaxTransmissionTime