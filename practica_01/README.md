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

`Usage: java -jar practica_01.jar seed nServers nRepetitions nUsers nRequests algorithm initialState successorFunction heuristic`

seed, nServers, nRepetitions, nUsers, nRequests són nombres enters.

algorithm:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;hc --> HillClimbing

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sa --> SimulatedAnnealing

initialState:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;fastest --> assign each request to the server with less delay

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;random  --> for random assignation

successorFunction (operator)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;moveSlowest --> moves slowest file from lowest server

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;second&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;--> //TODO

heuristic:

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;best&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  --> take into account maxTransmissionTime and the std from all servers

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;slowest --> only checks MaxTransmissionTime