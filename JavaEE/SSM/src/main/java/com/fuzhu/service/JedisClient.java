package com.fuzhu.service;

/**
 * @FileName: JedisClient
 * @author: qianBaoLi
 * @date: 2020/11/28 13:52
 * @Description: null
 */

public interface JedisClient {
    public long  hset(String hkey, String key, String value);
    public String hget(String hkey, String key);
}
