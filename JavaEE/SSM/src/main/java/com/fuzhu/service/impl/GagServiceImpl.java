package com.fuzhu.service.impl;

import com.fuzhu.dao.GagDao;
import com.fuzhu.entity.Gag;
import com.fuzhu.service.GagService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * @FileName: GagServiceImpl
 * @author: qianBaoLi
 * @date: 2020/11/28 11:03
 * @Description: null
 */
@Service
public class GagServiceImpl implements GagService {
    @Autowired
    private GagDao gagDao;

    @Override
    public int insertGag(Gag gag) {
        int t = gagDao.insertGag(gag);
        return t;
    }

    @Override
    public List<Gag> findByUserId(Long id) {
        List<Gag> gagList = gagDao.findByUserId(id);
        return gagList;
    }
}
