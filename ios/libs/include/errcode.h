#ifndef __ERROR_CODE_H__
#define __ERROR_CODE_H__

#ifdef  __cplusplus
extern "C" {
#endif

#define CPK_SUCCESS             0   //执行成功

/************************************************************************/
/* COS接口错误号定义*/
/************************************************************************/
#define COS_CLA_ERR             1001  //CLA错误0x6E00
#define COS_INS_ERR             1002  //INS错误0x6D00
#define COS_READ_FAIL           1003  //COS读取数据失败
#define COS_WRITE_FAIL          1004  //COS写数据失败0x6581
#define COS_NO_SPACE            1006  //空间不足0x6A84
#define COS_P1P2_ERR            1007  //P1 P2参数错误0x6A86
#define COS_CARD_LOCK           1008  //功能不支持0x6A81
#define COS_NO_COND             1009  //使用条件不满足0x6985
#define ARRAY_BOUND_ERR         1010  //数据空间不足
#define COS_DATA_ERR            1011  //数据域参数错误0x6A80
#define COS_SECUR_ERR           1012  //不满足安全状态0x6982
#define DATA_TRANS_ERR          1013  //数据通讯错误  
#define EXT_AUTH_FAIL           1014  //外部认证失败
#define MAC_AUTH_FAIL           1015  //安全报文数据项不正确或MAC错误0x6988
#define DATA_LEN_ERR            1016  //数据长度错误
#define COS_NO_RAND             1017  //未取随机数0x6984
#define BUFFER_TOO_SMALL        1018  //缓冲区不足
#define COS_LE_ERR              1019  //LE错误0x6CXX
#define COS_NO_MAC              1020  //安全报文丢失0x6987
#define COS_FCI_ERR             1021  //文件控制信息错误0x698A
#define COS_TIME_ERR            1022  //时间错误0x698B
#define COS_CRC_ERR             1023  //CRC校验错误0x6A02

#define DEVICE_NOT_FOUND        2000  //设备ID错误
#define DEVICE_OPEN_FAILED      2001  //设备打开失败
#define DEVICE_CLOSE_FAILED     2002  //设备关闭失败
#define DEVICE_NOTOPEN_ERR      2003  //设备未打开
#define CONN_READER_FAIL        2004  //连接读卡器失败
#define USB_INIT_FAIL           2005  //USB初始化失败
#define CLAIM_INTERFACE_FAIL    2006  //USB调用接口失败
#define DEVICE_TYPE_ERR         2007  //设备类型错误(不支持的设备类型或未指定设备类型)

#define PIN_TYPE_ERR            3001  //PIN码类型错
#define PIN_VERIFY_ERR          3002  //PIN码校验错 
#define PIN_LEN_ERR             3003  //PIN码长度错 
#define PIN_LOCK_ERR            3004  //认证方式锁定0x6983

#define FILE_NOT_EXIST          4001  //文件不存在0x6A82
#define FILE_EXIST_ERR          4002  //文件已存在0x6A87  
#define FILE_TYPE_ERR           4003  //文件类型错0x6981
#define FILE_OFFSET_ERR         4004  //文件偏移错  
#define FILE_MAX_ERR            4005  //已达文件最大数  
#define FILE_IDTYPE_ERR         4007  //文件标识与文件类型不匹配
#define FILE_TOO_LEN            4008  //数据超过文件设定长度0x6A88
#define FILE_SPACE_ERR          4009  //分配的空间不足  
#define FILE_NAME_ERR           4010  //文件名错误
#define FILESYS_NO_EXIST        4011  //文件系统不存在或卡未初始化0x6A83
#define FILE_EMPTY_ERR          4012  //文件内容为空
#define EPK_NOT_EXIST           4013  //企业公钥不存在0x6A85
#define SPK_NOT_EXIST           4014  //系统公钥不存在0x6A89

#define ECCKEY_NO_MATCH         5001  //密钥不匹配
#define ECCKEY_LEN_ERR          5002  //私钥长度错  
#define KEY_INDEX_ERR           5003  //私钥ID码错  
#define COS_NO_KEY              5004  //没有密(私)钥(授权)数据0x6A03
#define RAND_LEN_ERR            5005  //随机数长度错误
#define KEYNUM_EXCESS_ERR       5006  //授权生产密钥个数已完
#define COS_NO_SKEY             5007  //没有会话密钥
#define SIGN_LEN_ERR            5008  //签名内容长度错
#define SIGN_VERIFY_FAIL        5009  //签名验证失败0x9302

#define COS_NO_LICENCE          6001  //设备、私钥、应用等未授权0x6A04
#define LICENCE_EXPIRED_ERR     6002  //授权过期0x6A05
#define EXPIRED_TERM_ERR        6003  //超过续费周期
#define LICENCE_NO_START        6004  //未到授权日期0x6A06
#define INIT_CC_ERR             6005  //初始化校验码错误

/************************************************************************/
/*应用接口错误号定义*/
/************************************************************************/
#define INVALID_PARAM           11001 //参数无效
#define INVALID_KEYCARD         11002 //无效密钥卡
#define INVALID_MATRIX          11003 //公钥矩阵不匹配
#define INVALID_ALGORITHM       11004 //算法无效
#define INVALID_DENVELOPE       11005 //无效密文数据
#define OPEN_FILE_FAIL          11006 //打开文件失败
#define MATRIX_NOT_fOUND        11008 //矩阵文件不存在
#define FILE_DELETE_ERR         11009 //删除文件错误
#define FILE_RENAME_ERR         11010 //文件重命名错误
#define DENVELOPE_TYPE_ERR      11011 //数字信封类型错误

#define MALLOC_FAIL             12001 //申请内存失败
#define CPK_VERSION_ERR         12002 //CPK版本错误
#define MD_LEN_ERR              12004 //摘要信息长度错误
#define FORMAT_CONVERSION_FAIL  12005 //格式转换错误
#define KEYCARD_NEW_FAIL        12007 //新建密钥结构对象失败
#define MATRIX_NEW_FAIL         12003 //新建矩阵结构对象失败

#define GET_MAPALG_FAIL         13001 //得到映射算法错误
#define GET_PRIVKEY_FAIL        13002 //得到私钥失败
#define GET_CIPHER_FAIL         13003 //得到加密算法
#define GET_DHKEY_FAIL          13004 //得到交换密钥失败

#define EVP_DIGEST_FAIL         14001 //HASH运算错误
#define EVP_ENCRYPT_FAIL        14002 //加密失败
#define EVP_DECRYPT_FAIL        14003 //解密失败
#define CPK_SIGN_FAIL           14004 //签名失败
#define CPK_VERIFY_FAIL         14005 //验证签名失败
#define CPK_APK_ERR             14006 //伴随密钥错误
#define CPK_ASIG_FAIL           14007 //验证伴随密钥签名失败
#define DECRYPT_ID_ERR          14008 //密钥标识错误
#define MATRIX_ID_ERR           14009 //矩阵标识错误
#define FILE_VERSION_ERR        14010 //加密文件版本错误

#define BN_CONVERSION_FAIL      15001 //大整数类型转换错误
#define BN_NEW_FAIL             15002 //新建大整数失败
#define BN_RAND_FAIL            15003 //生成随机大整数失败
#define BN_INVERSE_FAIL         15004 //大整数求逆失败

#define ECP_FORMAT_ERR          16001 //椭圆曲线点格式错误
#define ECP_CONVERSION_FAIL     16002 //椭圆曲线点格式转换失败
#define ECP_NEW_FAIL            16003 //新建椭圆曲线点失败
#define ECP_MUL_FAIL            16004 //点乘失败
#define EC_GET_ORDER_FAIL       16005 //得到order失败
#define EC_GET_GROUP_FAIL       16006 //得到EC_GROUP错误
#define EC_KEY_NEW_FAIL         16007 //新建椭圆曲线KEY失败
#define EC_KEY_SET_FAIL         16008 //EC_KEY参数设置失败
#define EC_DSA_LEN_ERR          16009 //EC_DSA签名长度错误
#define EC_GROUP_DIFFER_ERR     16010 //椭圆曲线不同

#define SERVICE_NO_STARTUP      17001 //服务未启动
  
#ifdef  __cplusplus
}
#endif
  
#endif //__ERROR_CODE_H__
