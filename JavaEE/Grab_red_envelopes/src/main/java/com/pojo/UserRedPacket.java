package com.pojo;

import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.sql.Timestamp;

/**
 * @FileName: UserRedPacket
 * @author: qianBaoLi
 * @date: 2020/11/19 16:13
 * @Description: null
 */
@Getter
@Setter
public class UserRedPacket implements Serializable {
    private Long id;
    private Long redPacketId;
    private Long userId;
    private Double amount;
    private Timestamp grabTime;
    private String note;
    private static final long serialVersionUID = -5617482065991830143L;



}
