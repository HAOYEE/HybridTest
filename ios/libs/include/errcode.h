#ifndef __ERROR_CODE_H__
#define __ERROR_CODE_H__

#ifdef  __cplusplus
extern "C" {
#endif

#define CPK_SUCCESS             0   //ִ�гɹ�

/************************************************************************/
/* COS�ӿڴ���Ŷ���*/
/************************************************************************/
#define COS_CLA_ERR             1001  //CLA����0x6E00
#define COS_INS_ERR             1002  //INS����0x6D00
#define COS_READ_FAIL           1003  //COS��ȡ����ʧ��
#define COS_WRITE_FAIL          1004  //COSд����ʧ��0x6581
#define COS_NO_SPACE            1006  //�ռ䲻��0x6A84
#define COS_P1P2_ERR            1007  //P1 P2��������0x6A86
#define COS_CARD_LOCK           1008  //���ܲ�֧��0x6A81
#define COS_NO_COND             1009  //ʹ������������0x6985
#define ARRAY_BOUND_ERR         1010  //���ݿռ䲻��
#define COS_DATA_ERR            1011  //�������������0x6A80
#define COS_SECUR_ERR           1012  //�����㰲ȫ״̬0x6982
#define DATA_TRANS_ERR          1013  //����ͨѶ����  
#define EXT_AUTH_FAIL           1014  //�ⲿ��֤ʧ��
#define MAC_AUTH_FAIL           1015  //��ȫ�����������ȷ��MAC����0x6988
#define DATA_LEN_ERR            1016  //���ݳ��ȴ���
#define COS_NO_RAND             1017  //δȡ�����0x6984
#define BUFFER_TOO_SMALL        1018  //����������
#define COS_LE_ERR              1019  //LE����0x6CXX
#define COS_NO_MAC              1020  //��ȫ���Ķ�ʧ0x6987
#define COS_FCI_ERR             1021  //�ļ�������Ϣ����0x698A
#define COS_TIME_ERR            1022  //ʱ�����0x698B
#define COS_CRC_ERR             1023  //CRCУ�����0x6A02

#define DEVICE_NOT_FOUND        2000  //�豸ID����
#define DEVICE_OPEN_FAILED      2001  //�豸��ʧ��
#define DEVICE_CLOSE_FAILED     2002  //�豸�ر�ʧ��
#define DEVICE_NOTOPEN_ERR      2003  //�豸δ��
#define CONN_READER_FAIL        2004  //���Ӷ�����ʧ��
#define USB_INIT_FAIL           2005  //USB��ʼ��ʧ��
#define CLAIM_INTERFACE_FAIL    2006  //USB���ýӿ�ʧ��
#define DEVICE_TYPE_ERR         2007  //�豸���ʹ���(��֧�ֵ��豸���ͻ�δָ���豸����)

#define PIN_TYPE_ERR            3001  //PIN�����ʹ�
#define PIN_VERIFY_ERR          3002  //PIN��У��� 
#define PIN_LEN_ERR             3003  //PIN�볤�ȴ� 
#define PIN_LOCK_ERR            3004  //��֤��ʽ����0x6983

#define FILE_NOT_EXIST          4001  //�ļ�������0x6A82
#define FILE_EXIST_ERR          4002  //�ļ��Ѵ���0x6A87  
#define FILE_TYPE_ERR           4003  //�ļ����ʹ�0x6981
#define FILE_OFFSET_ERR         4004  //�ļ�ƫ�ƴ�  
#define FILE_MAX_ERR            4005  //�Ѵ��ļ������  
#define FILE_IDTYPE_ERR         4007  //�ļ���ʶ���ļ����Ͳ�ƥ��
#define FILE_TOO_LEN            4008  //���ݳ����ļ��趨����0x6A88
#define FILE_SPACE_ERR          4009  //����Ŀռ䲻��  
#define FILE_NAME_ERR           4010  //�ļ�������
#define FILESYS_NO_EXIST        4011  //�ļ�ϵͳ�����ڻ�δ��ʼ��0x6A83
#define FILE_EMPTY_ERR          4012  //�ļ�����Ϊ��
#define EPK_NOT_EXIST           4013  //��ҵ��Կ������0x6A85
#define SPK_NOT_EXIST           4014  //ϵͳ��Կ������0x6A89

#define ECCKEY_NO_MATCH         5001  //��Կ��ƥ��
#define ECCKEY_LEN_ERR          5002  //˽Կ���ȴ�  
#define KEY_INDEX_ERR           5003  //˽ԿID���  
#define COS_NO_KEY              5004  //û����(˽)Կ(��Ȩ)����0x6A03
#define RAND_LEN_ERR            5005  //��������ȴ���
#define KEYNUM_EXCESS_ERR       5006  //��Ȩ������Կ��������
#define COS_NO_SKEY             5007  //û�лỰ��Կ
#define SIGN_LEN_ERR            5008  //ǩ�����ݳ��ȴ�
#define SIGN_VERIFY_FAIL        5009  //ǩ����֤ʧ��0x9302

#define COS_NO_LICENCE          6001  //�豸��˽Կ��Ӧ�õ�δ��Ȩ0x6A04
#define LICENCE_EXPIRED_ERR     6002  //��Ȩ����0x6A05
#define EXPIRED_TERM_ERR        6003  //������������
#define LICENCE_NO_START        6004  //δ����Ȩ����0x6A06
#define INIT_CC_ERR             6005  //��ʼ��У�������

/************************************************************************/
/*Ӧ�ýӿڴ���Ŷ���*/
/************************************************************************/
#define INVALID_PARAM           11001 //������Ч
#define INVALID_KEYCARD         11002 //��Ч��Կ��
#define INVALID_MATRIX          11003 //��Կ����ƥ��
#define INVALID_ALGORITHM       11004 //�㷨��Ч
#define INVALID_DENVELOPE       11005 //��Ч��������
#define OPEN_FILE_FAIL          11006 //���ļ�ʧ��
#define MATRIX_NOT_fOUND        11008 //�����ļ�������
#define FILE_DELETE_ERR         11009 //ɾ���ļ�����
#define FILE_RENAME_ERR         11010 //�ļ�����������
#define DENVELOPE_TYPE_ERR      11011 //�����ŷ����ʹ���

#define MALLOC_FAIL             12001 //�����ڴ�ʧ��
#define CPK_VERSION_ERR         12002 //CPK�汾����
#define MD_LEN_ERR              12004 //ժҪ��Ϣ���ȴ���
#define FORMAT_CONVERSION_FAIL  12005 //��ʽת������
#define KEYCARD_NEW_FAIL        12007 //�½���Կ�ṹ����ʧ��
#define MATRIX_NEW_FAIL         12003 //�½�����ṹ����ʧ��

#define GET_MAPALG_FAIL         13001 //�õ�ӳ���㷨����
#define GET_PRIVKEY_FAIL        13002 //�õ�˽Կʧ��
#define GET_CIPHER_FAIL         13003 //�õ������㷨
#define GET_DHKEY_FAIL          13004 //�õ�������Կʧ��

#define EVP_DIGEST_FAIL         14001 //HASH�������
#define EVP_ENCRYPT_FAIL        14002 //����ʧ��
#define EVP_DECRYPT_FAIL        14003 //����ʧ��
#define CPK_SIGN_FAIL           14004 //ǩ��ʧ��
#define CPK_VERIFY_FAIL         14005 //��֤ǩ��ʧ��
#define CPK_APK_ERR             14006 //������Կ����
#define CPK_ASIG_FAIL           14007 //��֤������Կǩ��ʧ��
#define DECRYPT_ID_ERR          14008 //��Կ��ʶ����
#define MATRIX_ID_ERR           14009 //�����ʶ����
#define FILE_VERSION_ERR        14010 //�����ļ��汾����

#define BN_CONVERSION_FAIL      15001 //����������ת������
#define BN_NEW_FAIL             15002 //�½�������ʧ��
#define BN_RAND_FAIL            15003 //�������������ʧ��
#define BN_INVERSE_FAIL         15004 //����������ʧ��

#define ECP_FORMAT_ERR          16001 //��Բ���ߵ��ʽ����
#define ECP_CONVERSION_FAIL     16002 //��Բ���ߵ��ʽת��ʧ��
#define ECP_NEW_FAIL            16003 //�½���Բ���ߵ�ʧ��
#define ECP_MUL_FAIL            16004 //���ʧ��
#define EC_GET_ORDER_FAIL       16005 //�õ�orderʧ��
#define EC_GET_GROUP_FAIL       16006 //�õ�EC_GROUP����
#define EC_KEY_NEW_FAIL         16007 //�½���Բ����KEYʧ��
#define EC_KEY_SET_FAIL         16008 //EC_KEY��������ʧ��
#define EC_DSA_LEN_ERR          16009 //EC_DSAǩ�����ȴ���
#define EC_GROUP_DIFFER_ERR     16010 //��Բ���߲�ͬ

#define SERVICE_NO_STARTUP      17001 //����δ����
  
#ifdef  __cplusplus
}
#endif
  
#endif //__ERROR_CODE_H__
