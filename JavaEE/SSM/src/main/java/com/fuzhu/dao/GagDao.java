package com.fuzhu.dao;

import com.fuzhu.entity.Gag;

import java.util.List;

/**
 * @FileName: GagDao
 * @author: qianBaoLi
 * @date: 2020/11/28 10:50
 * @Description: null
 */
public interface GagDao {
    public int insertGag(Gag gag);
    List<Gag> findByUserId(Long id);
}
