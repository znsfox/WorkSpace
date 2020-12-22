package com.config;

import org.springframework.web.servlet.support.AbstractAnnotationConfigDispatcherServletInitializer;

import javax.servlet.MultipartConfigElement;
import javax.servlet.ServletRegistration;

/**
 * @FileName: WebAppInitializer
 * @author: qianBaoLi
 * @date: 2020/11/20 15:05
 * @Description: null
 */
public class WebAppInitializer extends AbstractAnnotationConfigDispatcherServletInitializer {

    // Spring IoC环境配置
    @Override
    protected Class<?>[] getRootConfigClasses() {
        // 配置Spring IoC资源
        return new Class<?>[] { RootConfig.class };
    }

    // DispatcherServlet环境配置
    @Override
    protected Class<?>[] getServletConfigClasses() {
        // 加载Java配置类
        return new Class<?>[] { WebConfig.class };
    }

    // DispatchServlet拦截请求配置
    @Override
    protected String[] getServletMappings() {
        return new String[] { "*.do" };
    }

    /**
     * @param dynamic
     *            Servlet上传文件配置.
     */
    @Override
    protected void customizeRegistration(ServletRegistration.Dynamic dynamic) {
        // 配置上传文件路径
        String filepath = "c:/Users/fox/Documents/mvc/uploads";
        // 5MB
        Long singleMax = (long) (5 * Math.pow(2, 20));
        // 10MB
        Long totalMax = (long) (10 * Math.pow(2, 20));
        // 设置上传文件配置
        dynamic.setMultipartConfig(new MultipartConfigElement(filepath, singleMax, totalMax, 0));
    }

}
