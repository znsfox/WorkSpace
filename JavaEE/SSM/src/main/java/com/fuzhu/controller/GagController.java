package com.fuzhu.controller;

import com.alibaba.druid.support.json.JSONUtils;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONArray;
import com.fuzhu.dao.GagDao;
import com.fuzhu.entity.Gag;
import com.fuzhu.service.GagService;
import com.fuzhu.service.JedisClient;
import com.fuzhu.service.impl.JedisClientSingle;
import com.fuzhu.utils.JsonUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * @FileName: GagController
 * @author: qianBaoLi
 * @date: 2020/11/28 11:11
 * @Description: null
 */
@RestController
@RequestMapping("/gag")
public class GagController {
    //装配需要的东东先！！
    @Autowired
    private GagService gagService;
    @Autowired
    private JedisClient jedisClient;
    //再写个业务方法
//基本思路：有没有查过禁言表，有查过就往redis拿，null的话就去数据库拿，拿完再把数据set进缓存！！
    @RequestMapping(value = "/testRedis",produces="text/html;charset=UTF-8", method = {RequestMethod.GET,RequestMethod.GET})
    public String testRedis(Long id){
        List<Gag> gagList= null;
        try {
            String resulthget = jedisClient.hget("禁言表", id + "");
            if (resulthget != null) {
                //字符串转为list
                System.out.println("有缓存啦啦啦！！！");
                JSONArray array = JSONArray.parseArray(resulthget);
                gagList = (List) array;
            } else {
                System.out.println("禁言表没查过");
                gagList= gagService.findByUserId(id);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        try {
            String cacheString = JsonUtils.objectToJson(gagList);
            jedisClient.hset("禁言表", id + "", cacheString);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return JSON.toJSONString(gagList);
    }

}
