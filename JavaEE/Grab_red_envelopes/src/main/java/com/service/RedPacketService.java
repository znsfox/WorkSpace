package com.service;

import org.apache.ibatis.annotations.Param;
import com.pojo.RedPacket;

/**
 * @FileName: RedPacketService
 * @author: qianBaoLi
 * @date: 2020/11/19 17:07
 * @Description: null
 */
public interface RedPacketService {
    /**
     * get the RedPacket
     * @param id Number
     * @return the information of RedPacket
     */
    public RedPacket getRedPacket(@Param("id") Long id);

    /**
     * decrease RedPacket
     * @param id Number
     * @return affect number
     */
    public int decreaseRedPacket(@Param("id") Long id);
}
