//File Name: cpkdev.h

#ifndef __CPK_DEV_H__
#define __CPK_DEV_H__

#ifdef  __cplusplus
extern "C" {
#endif

//the declaration of KeyIndex enum
enum KeyIndex{
    SERIAL_NUMBER = 0x00,
    REAL_NAME,
    CELL_PHONE,
    EMAIL,
    IDCARD,
    BANK_CARD,
    RESERVED1,
    RESERVED2,
    RESERVED3,
    RESERVED4,
    RESERVED5,
    RESERVED6,
    RESERVED7,
    RESERVED8,
    RESERVED9,
    RESERVED10,
};

#ifndef CPK_RV
#define CPK_RV int
#endif

/**********************************************************************************/
/* Function:
 *   int DevOpen(int devType, const char *vkeyFile = 0)
 *
 * Purpose:
 *   Open device
 *
 * Parameters:
 *   devType
 *       [in] device type (0:CPK Key; 1:CPK Card; 2:TF Card; 3:CPK SKey; 4:CPK PKey; 5:CPK VDev)
 *   vkeyFile
 *       [in] virtual key's filename including path
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *	 If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevOpen(int devType, const char *vkeyFile/* = 0*/);

/**********************************************************************************/
/* Function:
 *   int DevClose()
 *
 * Purpose:
 *   Reset security status and disconnect device
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevClose();

/**********************************************************************************/
/* Function:
 *   int DevReset();
 *
 * Purpose:
 *   Reset security status
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevReset();

/**********************************************************************************/
/* Function:
 *   int DevGetSn(char *sn, int *snLen)
 *
 * Purpose:
 *   Get serial number (hex strings)
 *
 * Parameters:
 *   sn
 *       [out] serial number
 *   snLen
 *       [in] specifies the maximum size of the buffer
 *       [out] return the size of serial number
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevGetSn(char *sn, int *snLen);

/**********************************************************************************/
/* Function:
 *   int DevVerfiyPin(unsigned char pinType, const char *pin, int *times)
 *
 * Purpose:
 *   Verify personal identification number and modify security status register
 *
 * Parameters:
 *   pinType
 *       [in] 1 is super user; 2 is common user
 *   pin
 *       [in] personal identification number
 *   times
 *       [out] remain retry times for pin, default value is five
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevVerifyPin(unsigned char pinType, const char *pin, int *times);

/**********************************************************************************/
/* Function:
 *	 int DevSetCachePin(int isCache, int days)
 *
 * Purpose:
 *	 Set Cache PIN
 *
 * Parameters:
 *   isCache
 *		 [in] 1: set; 0: cancel
 *   days
 *		 [in] number of day
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevSetCachePin(int isCache, int days);

/**********************************************************************************/
/* Function:
 *   int DevAutoVerify()
 *
 * Purpose:
 *   Automatic login (no user pin)
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevAutoVerify();

/**********************************************************************************/
/* Function:
 *   int DevModifyPin(unsigned char pinType, const char *oldPin, const char *newPin)
 *
 * Purpose:
 *   Modify person identification number
 *
 * Parameters:
 *   pinType
 *       [in] pin type
 *   oldPin
 *       [in] old pin
 *   newPin
 *       [in] new pin
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevModifyPin(unsigned char pinType, const char *oldPin, const char *newPin);

/**********************************************************************************/
/* Function:
 *   int DevReloadPin(unsigned char pinType, const char *newPin)
 *
 * Purpose:
 *   Reload personal identification number
 *
 * Parameters:
 *   pinType
 *       [in] pin type
 *   newPin
 *       [in] new pin
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevReloadPin(unsigned char pinType, const char *newPin);

/**********************************************************************************/
/* Function:
 *   int DevUnlockPin(unsigned char pinType) 
 *
 * Purpose:
 *   Reset the retry times of pin
 *
 * Parameters:
 *   pinType
 *       [in] pin type
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevUnlockPin(unsigned char pinType);

/**********************************************************************************/
/* Function:
 *   int DevGetRandom(unsigned char *rand, int randLen)
 *
 * Purpose:
 *   Get true random number
 *
 * Parameters:
 *   rand
 *       [out] true random number
 *   randLen
 *       [in] specifies the size of the buffer and need the bytes of random number
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevGetRandom(unsigned char *rand, int randLen);

/**********************************************************************************/
/* Function:
 *   int DevCreateFile(unsigned char fileId)
 *
 * Purpose:
 *   Create new file
 *
 * Parameters:
 *   fileId
 *       [in] the identity of file
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevCreateFile(unsigned char fileId);

/**********************************************************************************/
/* Function:
 *   int DevFileIsExist(unsigned char fileId)
 *
 * Purpose:
 *   Determines if file is exist
 *
 * Parameters:
 *   fileId
 *       [in] the identity of file
 *
 * Return Values:
 *   If the file is exist, the return value is nozero.
 *   If the file is not exist, the return value is zero. */
/**********************************************************************************/
CPK_RV DevFileIsExist(unsigned char fileId);

/**********************************************************************************/
/* Function:
 *   int DevWriteFile(unsigned char fileId, const unsigned char *data, int dataLen)
 *
 * Purpose:
 *   Write file
 *
 * Parameters:
 *   fileId
 *       [in] the identity of file
 *   data
 *       [in] the context of file
 *   dataLen
 *       [in] the length of data
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevWriteFile(unsigned char fileId, const unsigned char *data, int dataLen);

/**********************************************************************************/
/* Function:
 *   int DevGetFileLen(unsigned char fileId, int *fileLen)
 *
 * Purpose:
 *   Get the length of file
 *
 * Parameters:
 *   fileId
 *       [in] the identity of file
 *   fileLen
 *       [out] the length of file
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevGetFileLen(unsigned char fileId, int *fileLen);

/**********************************************************************************/
/* Function:
 *   int DevReadFile(unsigned char fileId, unsigned char *data, int *dataLen)
 *
 * Purpose:
 *   Read file
 *
 * Parameters:
 *   fileId
 *       [in] the identity of file
 *   data
 *       [out] the context of file
 *   dataLen
 *       [in] specifies the maximum size of the buffer
 *       [out] return the length of context
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevReadFile(unsigned char fileId, unsigned char *data, int *dataLen);

/**********************************************************************************/
/* Function:
 *   int DevDeleteFile(unsigned char fileId)
 *
 * Purpose:
 *   Delete file
 *
 * Parameters:
 *   fileId
 *       [in] the identity of file
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevDeleteFile(unsigned char fileId);

/**********************************************************************************/
/* Function:
 *   int DevGenKeyCard(const char* keyId, int keyIdLen, unsigned int period, 
 *                     const unsigned char *skey, unsigned char* keyCard, int* keyCardLen)
 *
 * Purpose:
 *   Generate key card by chip
 *
 * Parameters:
 *   keyId
 *       [in] key identity
 *   keyIdLen
 *       [in] the length of key identity
 *   period
 *       [in] period of validity, unit year
 *   skey
 *		 [in] session key for encryption
 *   keyCard
 *       [out] key card
 *   keyCardLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of key card
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevGenKeyCard(const char* keyId, int keyIdLen, unsigned int period,
					 const unsigned char *skey, unsigned char* keyCard, int* keyCardLen);

/**********************************************************************************/
/* Function:
 *   int DevGenKeyApply(const char *pubmatrix, const char *serverId, unsigned char *env, 
 *			       int *envLen)
 *
 * Purpose:
 *   Generate simplify digital envelope
 *
 * Parameters:
 *   pubmatrix
 *       [in] the filename of public matrix including path
 *   serverId
 *       [in] server identity of kms
 *   env
 *       [out] digital envelope
 *   envLen
 *       [in] specifies the maximum size of the buffer
 *       [out] return the length of digital envelope
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevGenKeyApply(const char *pubmatrix, const char *serverId, unsigned char *env, 
				 int *envLen);

/**********************************************************************************/
/* Function:
 *   int DevWriteKeyCard(unsigned char keyIndex, int mode, const unsigned char *data, 
 *                       int dataLen)
 *
 * Purpose:
 *   Write key card to device
 *
 * Parameters:
 *   keyIndex
 *       [in] the index of key card
 *   mode
 *       [in] packet mode (1: cleartext; 0: ciphertext)
 *   data
 *       [in] the data of key card
 *   dataLen
 *       [in] the length of data
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevWriteKeyCard(unsigned char keyIndex, int mode, const unsigned char *data, 
					   int dataLen);

/**********************************************************************************/
/* Function:
 *   int DevGetKeyId(int isAll, unsigned char keyIndex, char *keyId, int *keyIdLen)
 *
 * Purpose:
 *   Get key's identity
 *
 * Parameters:
 *   isAll
 *       [in] whether including matrix's identity(0: only key identity; 
 *            1: including matrix identity)
 *   keyIndex
 *       [in] the index of key card
 *   keyId
 *       [in] the identity of key card
 *   keyIdLen
 *       [in] specifies the maximum size of the buffer
 *       [out] return the length of key identity
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevGetKeyId(int isAll, unsigned char keyIndex, char *keyId, int *keyIdLen);

/**********************************************************************************/
/* Function:
 *   int DevSignData(unsigned char keyIndex, const unsigned char *data, int dataLen, 
 *	                 unsigned char *signVal, int *signValLen)
 *
 * Purpose:
 *   ECDSA signature
 *
 * Parameters:
 *   keyIndex
 *       [in] the index of key card
 *   data
 *       [in] signed data
 *   dataLen
 *       [in] the length of data
 *   signVal
 *       [out] signature value
 *   signValLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of signature value
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevSignData(unsigned char keyIndex, const unsigned char *data, int dataLen, 
				   unsigned char *signVal, int *signValLen);

/**********************************************************************************/
/* Function:
 *   int DevSignFile(unsigned char keyIndex, const char *filename, unsigned char *signVal,
 *                   int *signValLen)
 *
 * Purpose:
 *   Signature file
 *
 * Parameters:
 *   keyIndex
 *       [in] the index of key card
 *   filename
 *       [in] filename including path
 *   signVal
 *       [out] signature value
 *   signValLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of signature value
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevSignFile(unsigned char keyIndex, const char *filename, unsigned char *signVal,
				int *signValLen);

/**********************************************************************************/
/* Function:
 *   int DevDecryptData(unsigned char keyIndex, const unsigned char *ciphertext, 
 *                      int cipherLen, unsigned char *cleartext, int *clearLen)
 *
 * Purpose:
 *   Data decryption
 *
 * Parameters:
 *   keyIndex
 *       [in] the index of key card
 *   ciphertext
 *       [in] encrypt data
 *   cipherLen
 *       [in] the length of ciphertext
 *   cleartext
 *       [out] clear data
 *   clearLen
 *       [in] specifies the maximum size of the buffer
 *       [out] return the length of clear data
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevDecryptData(unsigned char keyIndex, const unsigned char *ciphertext, 
					  int cipherLen, unsigned char *cleartext, int *clearLen);

/**********************************************************************************/
/* Function:
 *   int DevDecryptFile(unsigned char keyIndex, const char *sfilename,
 *                      const char *ofilename)
 *
 * Purpose:
 *   Decrypt file
 *
 * Parameters:
 *   keyIndex
 *       [in] the index of key card
 *   sfilename
 *       [in] source filename including path
 *   ofilename
 *       [in] object filename including path
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevDecryptFile(unsigned char keyIndex, const char *sfilename, 
					  const char *ofilename);

/**********************************************************************************/
/* Function:
 *   int DevGenEnv(const char *pubmatrix, const char *addresseeId, unsigned char *env, 
 *			       int *envLen)
 *
 * Purpose:
 *   Generate simplify digital envelope
 *
 * Parameters:
 *   pubmatrix
 *       [in] the filename of public matrix including path
 *   addresseeId
 *       [in] addressee's identity
 *   env
 *       [out] digital envelope
 *   envLen
 *       [in] specifies the maximum size of the buffer
 *       [out] return the length of digital envelope
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevGenEnv(const char *pubmatrix, const char *addresseeId, unsigned char *env, 
				 int *envLen);

/**********************************************************************************/
/* Function:
 *	 int DevCalDHKey(unsigned char keyIndex, const char *pubmatrix, const char *addreseeId, 
 *                   unsigned char *skey, int *skeyLen); 
 *
 * Purpose:
 *	 Calculate ECDH session key
 *
 * Parameters:
 *   pubmatrix
 *       [in] the filename of public matrix including path
 *	 keyIndex
 *	     [in] the index of key card
 *   addresseeId
 *       [in] addressee's identity
 *   skey
 *       [out] session key
 *   skeyLen
 *       [in] specifies the maximum size of the buffer
 *       [out] return the length of session key
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevCalDHKey(unsigned char keyIndex, const char *pubmatrix, const char *addresseeId, 
				   unsigned char *skey, int *skeyLen);

/**********************************************************************************/
/* Function:
 *   int DevOpenDE(unsigned char keyIndex, unsigned char *rbG, unsigned char *rG)
 *
 * Purpose:
 *   Open digital envelope and get session key
 *
 * Parameters:
 *   keyIndex
 *       [in] the index of key card
 *   rbG
 *       [in] ditital envelope (elliptical curve point)
 *   rG
 *       [out] session key (elliptical curve point)
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevOpenDE(unsigned char keyIndex, unsigned char *rbG, unsigned char *rG);

/**********************************************************************************/
/* Function:
 *   int DevOpenEnv(int isExport, unsigned char keyIndex, unsigned char *env, 
 *                  int envLen, unsigned char *skey, int *skeyLen)
 *
 * Purpose:
 *   Open digital envelope
 *
 * Parameters:
 *   isExport
 *       [in] if isExport is zero, session key save chip memory; else session key export
 *   keyIndex
 *       [in] the index of key card
 *   env
 *       [in] digital envelope (from chip)
 *   envLen
 *       [in] the length of digital envelope
 *   skey
 *       [out] session key
 *   skeyLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of session key
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevOpenEnv(int isExport, unsigned char keyIndex, unsigned char *env, 
	              int envLen, unsigned char *skey, int *skeyLen); 

/**********************************************************************************/
/* Function:
 *   int DevOpenEnvelope(unsigned char keyIndex, const unsigned char *env, int envLen, 
 *                       unsigned char *skey, int *skeyLen)
 *
 * Purpose:
 *   Open digital envelope and get session key
 *
 * Parameters:
 *   keyIndex
 *       [in] the index of key card
 *   env
 *       [in] digital envelope (from memory)
 *   envLen
 *       [in] the length of digital envelope
 *   skey
 *       [out] session key
 *   skeyLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of session key
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevOpenEnvelope(unsigned char keyIndex, const unsigned char *env, int envLen, 
					   unsigned char *skey, int *skeyLen); 

/**********************************************************************************/
/* Function:
 *   int DevSwapEnv(const unsigned char *skeyr, unsigned int rLen, const char *pubmatrix, 
 *                  const char *addresseeId, unsigned char *cenv, int *cenvLen);
 *
 * Purpose:
 *   Swap digital envelope
 *
 * Parameters:
 *   skeyr
 *       [in] the random of session key(i.e. r of rG)
 *   rLen
 *       [in] the length of skeyr
 *   pubmatrix
 *       [in] public matrix including path
 *   addresseeId
 *       [in] the identity of addressee
 *   cenv
 *       [out] client digital envelope
 *   cenvLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of client digital envelope
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevSwapEnv(const unsigned char *skeyr, unsigned int rLen, const char *pubmatrix, 
				  const char *addresseeId, unsigned char *cenv, int *cenvLen);

/**********************************************************************************/
/* Function:
 *   int DevSymEncrypt(unsigned char P1, const unsigned char *cleartext, int clearLen, 
 *                     unsigned char *ciphertext, int *cipherLen)
 *
 * Purpose:
 *   Symmetrical encrypt in chip
 *
 * Parameters:
 *   P1
 *       [in] session key mode(00: key file; 01: digital envelope)
 *   cleartext
 *       [in] the data of cleartext
 *   clearLen
 *       [in] the length of cleartext
 *   ciphertext
 *       [out] the data of ciphertext
 *   cipherLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of ciphertext
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevSymEncrypt(unsigned char P1, const unsigned char *cleartext, int clearLen, 
					 unsigned char *ciphertext, int *cipherLen);

/**********************************************************************************/
/* Function:
 *   int DevSymDecrypt(unsigned char P1, const unsigned char *ciphertext, int cipherLen, 
 *					   unsigned char *cleartext, int *clearLen);
 *
 * Purpose:
 *   Symmetrical decrypt in chip
 *
 * Parameters:
 *   P1
 *       [in] session key mode(00: key file; 01: digital envelope)
 *   ciphertext
 *       [in] the data if ciphertext
 *   cipherLen
 *       [in] the length of ciphertext
 *   cleartext
 *       [out] the data of cleartext
 *   clearLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of cleartext
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevSymDecrypt(unsigned char P1, const unsigned char *ciphertext, int cipherLen, 
					 unsigned char *cleartext, int *clearLen);

/**********************************************************************************/
/* Function:
 *   int DevSHA1(const unsigned char *msg, int msgLen, unsigned char *md, int *mdLen)
 *
 * Purpose:
 *   Calculate message digest (SHA1 in chip)
 *
 * Parameters:
 *   msg
 *       [in] message data
 *   msgLen
 *       [in] the length of message data
 *   md
 *       [out] message digest
 *   mdLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of message digest
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevSHA1(const unsigned char *msg, int msgLen, unsigned char *md, int *mdLen);

/**********************************************************************************/
/* Function:
 *   int DevSM3(const unsigned char *msg, int msgLen, unsigned char *md, int *mdLen)
 *
 * Purpose:
 *   Calculate message digest (SM3 in chip)
 *
 * Parameters:
 *   msg
 *       [in] message data
 *   msgLen
 *       [in] the length of message data
 *   md
 *       [out] message digest
 *   mdLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of message digest
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV DevSM3(const unsigned char *msg, int msgLen, unsigned char *md, int *mdLen);

#ifdef  __cplusplus
}
#endif

#endif	//	__CPK_DEV_H__
