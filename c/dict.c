/*
 * 
 * [ leet , code , lan , yun , zhang ]
 * leet -> lan -> null
 * code -> null
 * yun  -> null
 * zhang -> null
 * 
 * /
 *
 * map["leet"] = 1
 * map["code"] = 1
 * map["zhang"] = 1
 *
 * TLE
 *
 * len = A.length - 1
 * dp[0][len] = dp[0][i] + dp[i][len]
 *
 * dp[i][j] =  1 if A[i,j] is in dict
 * else
 * dp[i][j] = dp[i][k] + dp[k+1][j] , [i,k] is word [k+1,j] is word
 *
 * dp[0][i] 
 */

