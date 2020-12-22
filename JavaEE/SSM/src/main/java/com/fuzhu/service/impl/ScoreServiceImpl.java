package com.fuzhu.service.impl;

import com.fuzhu.dao.ScoreDao;
import com.fuzhu.entity.Score;
import com.fuzhu.service.ScoreService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * @FileName: ScoreServiceImpl
 * @author: qianBaoLi
 * @date: 2020/11/27 14:19
 * @Description: null
 */
@Service
public class ScoreServiceImpl implements ScoreService {

    @Autowired
    private ScoreDao scoreDao;


    @Override
    public int insertScore(Score score) {
        int t = scoreDao.insertScore(score);
        return t;
    }
}
