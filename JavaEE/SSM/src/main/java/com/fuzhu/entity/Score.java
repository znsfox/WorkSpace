package com.fuzhu.entity;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * @FileName: Score
 * @author: qianBaoLi
 * @date: 2020/11/25 20:56
 * @Description: null
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class Score {

    private Long id;
    //积分变化类型
    private String changeType;
    //创建时间
    private Date createTime;
    //积分变化数
    private Integer score;
    //爱豆变化者
    private User user;

    //省略无参构造器，全参构造器，以及一系列的getset
}


