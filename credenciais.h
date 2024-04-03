#ifndef CREDENCIAIS_H
#define CREDENCIAIS_H

// Arrays de SSIDs e senhas
const String listaSsids[] = {"SSID1", "SSID2", "SSID3", "SSID4", "SSID5"}; // Lista de SSIDs para se conectar
const String listaSenhas[] = {"SENHA1", "SENHA2", "SENHA3", "SENHA4", "SENHA5"}; // Senha da rede Wi-Fi

// Número de SSIDs na lista
const int redes = sizeof(listaSsids) / sizeof(listaSsids[0]);

#endif