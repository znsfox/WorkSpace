package com.dao;

import org.springframework.stereotype.Repository;
import com.pojo.RedPacket;

/**
 * @FileName: RedPacketDao
 * @author: qianBaoLi
 * @date: 2020/11/19 16:19
 * @Description: null
 */
@Repository
public interface RedPacketDao {

    /**
     *get the information of RedPacket
     * @param id the id of RedPacket
     * @return the specify information of RedPaket
     */
    public RedPacket getRedPacket(Long id);

    /**
     * decrease the number of RedPacket
     * @param id the id of RedPacket
     * @return the number of update records
     */
    public int decreaseRedPacket(Long id);
}
