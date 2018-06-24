pragma solidity ^0.4.2;

contract ECDSA {
    
    
    function ECDSA ()
    {
        
    }
    
    function ECDSA_Verif () returns (address) {

        bytes32 hash = 0xA303D084C31A55BCE115C4CA365894D58E175E226D996A69A791EBE912278F69 ;//keccak256("hello") ;
    
        uint8   v = 27 ;
        bytes32 r = 0xC3FD887866D89685395B95C08FBDE27BF29D36082D1322E430193A4502BE1940 ;
        bytes32 s = 0x093864BE4A420E55C684D5F56126F4CFE0541E0F359B375C19A74244D9DE406B ;
    
        return ecrecover(hash, v, r, s) ;
    }
    
    function verify(bytes32 hash, uint8 v, bytes32 r, bytes32 s) constant returns(address) {

        bytes memory prefix = "\x19Ethereum Signed Message:\n32" ;
        bytes32 prefixedHash = sha3(prefix, hash) ;
        return ecrecover(prefixedHash, v, r, s)  ;
    }
    
}
