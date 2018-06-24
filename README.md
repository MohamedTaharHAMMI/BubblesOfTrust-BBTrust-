# BubblesOfTrust (BBTrust) : : a decentralized Blockchain-based authentication system for IoT


## What is BBTrust !

There is no doubt that Internet of Things (IoT) occupy a very important role in our daily lives. Indeed, numerous things that we 
use every time, are being equipped with electronic devices and protocol suites in order to make them interconnected and connected 
to the Internet. In IoT things process and exchange data without human intervention. Therefore, because of this full autonomy, 
these entities need to recognize and authenticate each other as well as to ensure the integrity of their exchanged data. Otherwise,
they will be the target of malicious users and malicious use. Due to the size and other features of IoT, it is almost impossible to
create an efficient centralized authentication system. To remedy this limit, in this work, we propose an original decentralized
system called bubbles of trust, which ensures a robust identification and authentication of devices. Furthermore,it protects the 
data integrity and availability. 

Our approach relies on the security advantages provided by blockchains, and serves to create secure virtual zones (bubbles)
where things can identify and trust each other. 

## How it is implemented ?

BBTrust is developped using:
- the C++ language [Qt framework] (https://www.qt.io/developers/); 
- Ethereum as blockchain (https://ethereum.org/);
- a smart contract that ensures our system functioning and which is developed using Solidity language (http://solidity.readthedocs.io/en/v0.4.24/); 
- for the interactions between end-nodes and the blockchain, we created a C++ interface that encode/decode data toward/from 
Ethereum. These interactions are realized using JSON Remote Procedure Call (RPC);
- TestRPC (https://github.com/ethereumjs/testrpc), which represents a Ethereum tool for testing and development purposes and that
emulates interactions to the blockchain without the overheads of running a real Ethereum node. An approach deployed using
TestRPC, acts exactly in the same way on the public Ethereum blockchain. Thus, BBTrust can be deployed on Ethereum
without any modifications. It works perfectly with geth (https://github.com/ethereum/go-ethereum);
- a lightweight and portable elliptic curve cryptographic library [master ecc] (https://github.com/kmackay/micro-ecc);
- a lightweight and portable sha3 library [sha3] (https://github.com/rhash/RHash/blob/master/librhash/sha3.c).


## How to install BBTrust ?

You need to download and install: 
- **Qt framework:** https://www.qt.io/download;
- **qjsonrpc:** https://bitbucket.org/devonit/qjsonrpc;
- a Ethereum client such as [**TestRPC**] (https://github.com/ethereumjs/testrpc) or [**geth**] (https://github.com/ethereum/go-ethereum);
- and ofcourse, the files of this project.

## Supported OS  
BBTrust is tested only on Linux-based :penguin: operating systems (https://www.linux.org/pages/download/) including the Raspbian distribution :grapes: (https://www.raspberrypi.org/downloads/). 
However, with minor modifications, it can be deployed also on other systems.

## How to execute & understand the principale of BBTrust ? 
- see :movie_camera: in: https://www.youtube.com/watch?v=XE13QGR1czE&feature=youtu.be;
- read our journal :scroll: untitled: Bubbles of Trust: a decentralized Blockchain-based authentication system for IoT.

## Contact
For any question please contact : hammi_mohamed_tahar@hotmail.fr  :+1:

