//
// Created by Leonov Oleksandr on 11/19/24.
//

#ifndef MC_READKEY_H
#define MC_READKEY_H

enum keys {

};

int mc_readkey(enum keys *);
int mc_mytermsave();
int mc_mytermrestore();
int mc_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);

#endif //MC_READKEY_H
