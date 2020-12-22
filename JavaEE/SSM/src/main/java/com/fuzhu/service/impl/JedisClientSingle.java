package com.fuzhu.service.impl;

import com.fuzhu.service.JedisClient;
import org.springframework.beans.factory.annotation.Autowired;
import redis.clients.jedis.Jedis;
import redis.clients.jedis.JedisPool;

/**
 * @FileName: JedisClientSingle
 * @author: qianBaoLi
 * @date: 2020/11/28 10:39
 * @Description: null
 */
public class JedisClientSingle implements JedisClient {

    @Autowired
    private JedisPool jedisPool;
    private int expiredTime = 60*60*24*2;

    @Override
    public long hset(String hkey, String key, String value) {
        Jedis jedis = jedisPool.getResource();
        Long result = jedis.hset(hkey, key, value);
        jedis.close();
        return result;
    }

    @Override
    public String hget(String hkey, String key) {
        System.out.println("JedisPool");
        Jedis jedis = jedisPool.getResource();
        String string = jedis.hget(hkey, key);
        jedis.close();
        return string;
    }
}
