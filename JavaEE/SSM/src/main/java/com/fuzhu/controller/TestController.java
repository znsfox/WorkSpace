package com.fuzhu.controller;

import com.alibaba.fastjson.JSON;
import com.fuzhu.entity.Score;
import com.fuzhu.service.ScoreService;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

/**
 * @FileName: testController
 * @author: qianBaoLi
 * @date: 2020/11/27 14:28
 * @Description: null
 */
@RestController
@RequestMapping("/test")
public class TestController {

    private Logger logger = LoggerFactory.getLogger(this.getClass());
    @Autowired
    private ScoreService scoreService;

    @RequestMapping(value = "/testMethod",produces="text/html;charset=UTF-8", method = {RequestMethod.GET,RequestMethod.GET})
    public String test() {
        Score score = new Score();
        score.setChangeType("玩游戏");
        score.setScore(10);
        scoreService.insertScore(score);
        return JSON.toJSONString(score);
    }
}

