package com.fuzhu.service;

import com.fuzhu.entity.Gag;

import java.util.List;

/**
 * @FileName: GagService
 * @author: qianBaoLi
 * @date: 2020/11/28 11:06
 * @Description: null
 */
public interface GagService {
    public int insertGag(Gag gag);
    List<Gag> findByUserId(Long id);
}
