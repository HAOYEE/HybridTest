#ifndef __CPK_SOFT_H__
#define __CPK_SOFT_H__

#ifdef  __cplusplus
extern "C" {
#endif

/****************sym encryption algorithm ****************/
/*AES */
#define AES_128_ECB "AES-128-ECB"
#define AES_128_CBC "AES-128-CBC"
#define AES_128_OFB "AES-128-OFB"
#define AES_128_CFB "AES-128-CFB"
#define AES_192_ECB "AES-192-ECB"
#define AES_192_CBC "AES-192-CBC"
#define AES_192_OFB "AES-192-OFB"
#define AES_192_CFB "AES-192-CFB"
#define AES_256_ECB "AES-256-ECB"
#define AES_256_CBC "AES-256-CBC"
#define AES_256_OFB "AES-256-OFB"
#define AES_256_CFB "AES-256-CFB"
#define AES_128_CFB1 "AES-128-CFB1"
#define AES_192_CFB1 "AES-192-CFB1"
#define AES_256_CFB1 "AES-256-CFB1"
#define AES_128_CFB8 "AES-128-CFB8"
#define AES_192_CFB8 "AES-192-CFB8"
#define AES_256_CFB8 "AES-256-CFB8"

/* DES */
#define DES_ECB "DES-ECB"
#define DES_CBC "DES-CBC"
#define DES_OFB "DES-OFB"
#define DES_CFB "DES-CFB"
#define DES_EDE "DES-EDE"
#define DES_EDE_CBC "DES-EDE-CBC"
#define DES_EDE_CFB "DES-EDE-CFB"
#define DES_EDE_OFB "DES-EDE-OFB"
#define DES_CFB1 "DES-CFB1"
#define DES_CFB8 "DES-CFB8"
/*3DES */
#define DES_EDE3 "DES-EDE3"
#define DES_EDE3_CFB "DES-EDE3-CFB"
#define DES_EDE3_OFB "DES-EDE3-OFB"
#define DES_EDE3_CFB8 "DES-EDE3-CFB8"
#define DES_EDE3_CBC "DES-EDE3-CBC"

/****************HASH algorithm****************/
/*MD*/
#define MD4 "MD4"
#define MD5 "MD5"
/*SHA */
#define SHA1  "SHA1"
#define SHA224 "SHA224"
#define SHA256 "SHA256"
#define SHA384 "SHA384"
#define SHA512 "SHA512"

#ifndef CPK_RV
#define CPK_RV int
#endif

typedef struct addressee_st 
{
	char addresseeId[128];
	char matrixId[32];
}ADDRESSEE;

/**********************************************************************************/
/* Function:
 *   int CPK_GetRandom(unsigned char* random, int randLen)
 *
 * Purpose:
 *   Get a random number
 *
 * Parameters:
 *   random
 *       [out] random number
 *   randLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of random number
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_GetRandom(unsigned char* random, int randLen);

/**********************************************************************************/
/* Function:
 *   int CPK_Verify_Data(const char *pubmatrix, const unsigned char *data, int dataLen, 
 *					     const unsigned char *signInfo, int signInfoLen)
 *
 * Purpose:
 *   Verify signature for data
 *
 * Parameters:
 *   pubmatrix
 *       [in] public matrix filename
 *   data
 *       [in] signed data
 *   dataLen
 *       [in] the length of data
 *   signInfo
 *       [in] signing message including auxiliary information
 *   signInfoLen
 *       [in] the length of signing message
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_Verify_Data(const char *pubmatrix, const unsigned char *data, int dataLen, 
					   const unsigned char *signInfo, int signInfoLen);

/**********************************************************************************/
/* Function:
 *   int CPK_Verify_File(const char *pubmatrix, const char *filename, 
 *		const unsigned char *signInfo, int signInfoLen)
 *
 * Purpose:
 *   Verify signing message whether validate
 *
 * Parameters:
 *   pubmatrix
 *       [in] public matrix filename
 *	filename
 *		[in] the name of signed file	
 *	signInfo
 *		[in] signing message
 *	signInfoLen
 *		[in] the length of signing message
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_Verify_File(const char *pubmatrix, const char *filename, 
					   const unsigned char *signInfo, int signInfoLen);

/**********************************************************************************/
/* Function:
 *   int CPK_GetSignerId(const unsigned char *signInfo, int signInfoLen, 
 *                       char *signerId, int *signerIdLen)
 *
 * Purpose:
 *   Get the identity of signer from signing message
 *
 * Parameters:
 *   signInfo
 *       [in] signing message
 *   signInfoLen
 *       [in] the length of signing message
 *   signerId
 *       [out] the identity of signer
 *   signerIdlen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of signer's identity
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_GetSignerId(const unsigned char *signInfo, int signInfoLen, 
					   char *signerId, int *signerIdLen);

/**********************************************************************************/
/* Function:
 *   int CPK_GetSignTime(const unsigned char *signInfo, int signInfoLen, 
 *		                 char *signTime, int *signTimeLen)
 *
 * Purpose:
 *   Get signature time from signing message
 *
 * Parameters:
 *   signInfo
 *       [in] signing message
 *   signInfoLen
 *       [in] the length of signing message
 *   signTime
 *       [out] signature time
 *   signTimeLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of signature time
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_GetSignTime(const unsigned char *signInfo, int signInfoLen,
	                   char *signTime,	int *signTimeLen);

/**********************************************************************************/
/* Function:
 *   int CPK_GetSignMatrixId(const unsigned char *signInfo, int signInfoLen, 
 *		                 char *matrixId, int *matrixIdLen)
 *
 * Purpose:
 *   Get signature time from signing message
 *
 * Parameters:
 *   signInfo
 *       [in] signing message
 *   signInfoLen
 *       [in] the length of signing message
 *   matrixId
 *       [out] the identity of matrix
 *   matrixIdLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of matrix identity
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_GetSignMatrixId(const unsigned char *signInfo, int signInfoLen, 
						   char *matrixId, int *matrixIdLen);

/**********************************************************************************/
/* Function:
 *   int CPK_Encrypt_Data(const char *pubmatrix, const char *addresseeId, 
 *	                      const unsigned char *clear, int clearLen, unsigned char *cipher, 
 *                        int *cipherLen)
 *
 * Purpose:
 *   Encrypt data by session key and generate digital envelope
 *
 * Parameters:
 *   pubmatrix
 *       [in] public matrix filename
 *   addresseeId
 *       [in] the identity of addressee
 *   clear
 *       [in] clear text
 *   clearLen
 *       [in] the length of clear text
 *   cipher
 *       [out] cipher text
 *   cipherLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of cipher text
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_Encrypt_Data(const char *pubmatrix, const char *addresseeId, 
						const unsigned char *clear, int clearLen, unsigned char *cipher, 
						int *cipherLen);

/**********************************************************************************/
/* Function:
 *   int CPK_Make_Envelope(const char *pubmatrix, const char *addresseeId, 
 *                         const unsigned char *skey, int skeyLen, unsigned char *env,
 *                         int *envLen)
 *
 * Purpose:
 *   Make digital envelope
 *
 * Parameters:
 *   pubmatrix
 *       [in] public matrix filename
 *   addresseeId
 *       [in] the identity of addressee
 *   skey
 *       [in] session key
 *   skeyLen
 *       [in] the length of session key
 *   env
 *       [out] digital envelope
 *   envLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of digital envelope
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_Make_Envelope(const char *pubmatrix, const char *addresseeId, 
	                     const unsigned char *skey, int skeyLen, unsigned char *env, 
						 int *envLen);

/**********************************************************************************/
/* Function:
 *   int CPK_Encrypt_File(const char *matrixPath, const ADDRESSEE *addressees, 
 *                        int arraySize, const char *sourceFile, const char *objFile, 
 *                        unsigned char *szr, int *rLen)
 *
 * Purpose:
 *   Encrypt File
 *
 * Parameters:
 *   matrixPath
 *       [in] the path of public matrix
 *   addressees
 *       [in] the array of addressee
 *   arraySize
 *       [in] the size of addressee's list
 *   sourceFile
 *       [in] source file
 *   objFile
 *       [in] object file
 *   szr
 *       [out] random number
 *   rLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of random number
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_Encrypt_File(const char *matrixPath, const ADDRESSEE *addressees, 
	                    int arraySize, const char *sourceFile, const char *destFile, 
						unsigned char *szr, int *rLen);

/**********************************************************************************/
/* Function:
 *   int CPK_GetEncMatrixId(const unsigned char *env, int envLen, char *matrixId,
 *                          int *matrixIdLen)
 *
 * Purpose:
 *   Get identity of matrix from digital envelope
 *
 * Parameters:
 *   env
 *       [in] digital envelope
 *   envLen
 *       [in] the length of digital envelope
 *   matrixId
 *       [out] the identity of matrix
 *   matrixIdLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of matrix's identity
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_GetEncMatrixId(const unsigned char *env, int envLen, char *matrixId, 
						  int *matrixIdLen);

/**********************************************************************************/
/* Function:
 *   int CPK_GetAddresseeId(const unsigned char *env, int envLen, char *addresseeId,
 *                          int *addresseeIdLen)
 *
 * Purpose:
 *   Get identity of addressee from digital envelope
 *
 * Parameters:
 *   env
 *       [in] digital envelope
 *   envLen
 *       [in] the length of digital envelope
 *   AddresseeId
 *       [out] the identity of addressee
 *   addresseeIdLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of addressee's identity
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_GetAddresseeId(const unsigned char *env, int envLen, char *addresseeId, 
						  int *addresseeIdLen);

/**********************************************************************************/
/* Function:
 *   int Sym_Encrypt(const char *szalg, const unsigned char *clear, int clearLen,
 *                   const unsigned char *symkey, int keyLen, unsigned char *cipher,
 *                   int *cipherLen)
 *
 * Purpose:
 *   Encrypt data by symmetrical algorithm
 *
 * Parameters:
 *   szalg
 *       [in] symmetrical algorithm
 *   clear
 *       [in] clear text
 *   clearLen
 *       [in] the length of clear text
 *   symkey
 *       [in] symmetrical key
 *   keyLen
 *       [in] the length of symmetrical key
 *   cipher
 *       [out] cipher text
 *   cipherLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of cipher text
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV Sym_Encrypt(const char *szalg, const unsigned char *clear, int clearLen, 
		           const unsigned char *symkey, int keyLen, unsigned char *cipher, 
				   int *cipherLen);

/**********************************************************************************/
/* Function:
 *   int Sym_Decrypt(const char *szalg, const unsigned char *cipher, int cipherLen, 
 *                   const unsigned char *symkey, int keyLen, unsigned char *clear, 
 *                   int *clearLen)
 *
 * Purpose:
 *   Decrypt data by symmetrical algorithm
 *
 * Parameters:
 *   szalg
 *       [in] symmetrical algorithm
 *   cipher
 *       [in] cipher text
 *   cipherLen
 *       [in] the length of cipher text
 *   symkey
 *       [in] symmetrical key
 *   keyLen
 *       [in] the length of symmetrical key
 *   clear
 *       [out] clear text
 *   clearLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of clear text
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV Sym_Decrypt(const char *szalg, const unsigned char *cipher, int cipherLen, 
				   const unsigned char *symkey, int keyLen, unsigned char *clear, 
				   int *clearLen);

/**********************************************************************************/
/* Function:
 *   int Hash(const char *szalg, const unsigned char *data, int dataLen,
 *            unsigned char *md, int *mdLen)
 *
 * Purpose:
 *   Calulate message digest
 *
 * Parameters:
 *   szalg
 *       [in] digest algorithm
 *   data
 *       [in] message
 *   dataLen
 *       [in] the length of message
 *    md
 *       [out] message digest
 *    mdLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of message digest
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV Hash(const char *szalg, const unsigned char *data, int dataLen, 
			unsigned char *md, int *mdLen);

/**********************************************************************************/
/* Function:
 *   int Base64Encode(const unsigned char* clear, int clearLen, char* base64, 
 *                    int* base64Len, int maxLineLen)
 *
 * Purpose:
 *   Base64 encode
 *
 * Parameters:
 *   clear
 *       [in] clear text
 *   clearLen
 *       [in] the length of clear text
 *   base64
 *       [out] base64 string
 *   base64Len
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of base64 string
 *   maxLineLen
 *       [in] max length of a line
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV Base64Encode(const unsigned char* clear, int clearLen, char* base64, 
					int* base64Len, int maxLineLen);

/**********************************************************************************/
/* Function:
 *   int Base64Decode(const char* base64, int base64Len, unsigned char* clear, int *clearLen)
 *
 * Purpose:
 *   Base64 decode
 *
 * Parameters:
 *   base64
 *       [in] base64 string
 *   base64len
 *       [in] lthe length of base64 string
 *   clear
 *       [out] clear text
 *   clearLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of clear text
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV Base64Decode(const char* base64, int base64Len, unsigned char* clear, int* clearLen);

/**********************************************************************************/
/* Function:
 *   int CPK_GenSymKey(const char *ecname, unsigned char *szkey, int *keyLen,
 *                     unsigned char *szr, int *rLen
 *
 * Purpose:
 *   Generate symmetrical key base on elliptical curve
 *
 * Parameters:
 *   ecname
 *       [in] elliptical curve's name
 *   szkey
 *       [out] symmetrical key
 *   keyLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of symmetrical key
 *   szr
 *       [out] random number (0<r<n)
 *   rLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of random number
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_GenSymKey(const char *ecname, unsigned char *szkey, int *keyLen,
					 unsigned char *szr, int *rLen);

/**********************************************************************************/
/* Function:
 *   int CPK_GenDE(const char *pubmatrix, const char *addresseeId, unsigned char *skey,
 *                 int *keyLen, unsigned char *de, int *deLen)
 *
 * Purpose:
 *   Generate digital envelope by public matrix's file
 *
 * Parameters:
 *   pubmatrix
 *       [in] public matrix file
 *   addresseeId
 *       [in] the identity of addressee
 *   skey
 *       [out] symmetrical key
 *   keyLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of symmetrical key
 *   de
 *       [out] digital envelope
 *   deLen
 *       [in] specifies the maximum size of the buffer
 *       [out] the length of digital envelope
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_GenDE(const char *pubmatrix, const char *addresseeId, unsigned char *skey, 
				 int *keyLen, unsigned char *de, int *deLen);

/**********************************************************************************/
/* Function:
 *   int CPK_ECP_x2xy(const char *ecname, const unsigned char *x, unsigned char y, 
 *                    unsigned char *xy)
 *
 * Purpose:
 *   Decompress elliptical curve point
 *
 * Parameters:
 *   ecname
 *       [in] elliptical curve's name
 *   x
 *       [in] EC_POINT.x
 *
 *   y
 *       [in] check code
 *   xy
 *       [out] elliptical curve point
 *
 * Return Values:
 *   If the function succeeds, the return value is zero.
 *   If the function fails, the return value is error code. */
/**********************************************************************************/
CPK_RV CPK_ECP_x2xy(const char *ecname, const unsigned char *x, unsigned char y, 
					unsigned char *xy);

#ifdef  __cplusplus
}
#endif

#endif
